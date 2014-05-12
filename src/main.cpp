#include "vrmlreader.h"
#include "gui.h"
#include "avatar.h"
#include "message_queue.h"
#include "client.h"
#include "executor.h"

#include <cstdlib>
#include <memory>
#include <iostream>
#include <unistd.h>
#include <thread>

#include <boost/asio.hpp> 
#include <boost/thread/thread.hpp>

#include <Inventor/Qt/SoQt.h>         
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>  
#include <Inventor/SoDB.h>         
#include <Inventor/errors/SoDebugError.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoNode.h>
#include <Inventor/nodes/SoTransform.h>
#include <Inventor/nodes/SoText3.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoPerspectiveCamera.h>
#include <Inventor/nodes/SoCamera.h>
#include <Inventor/nodes/SoEventCallback.h>
#include <Inventor/nodes/SoRotation.h>
#include <Inventor/nodes/SoTranslation.h>
#include <Inventor/nodes/SoSphere.h>
#include <Inventor/sensors/SoOneShotSensor.h>

#include <QDebug>
#include <QApplication>

const float maxSpeed = 100.0f;
const float minSpeed = -30.0f;
const float speedUp = 30.0f;
const float slowDown = 100.0f;
const float maxRotSpeed = 1.5;
const float minRotSpeed = -1.5;
const float rotSpeedUp = 6;   
const float rotSlowDown = 30; 

const float broacastPosition_interval = 1;
float broacastPosition_timePassed = 1;

struct KeyRec
{
  enum {
    UP = 0, DOWN, LEFT, RIGHT,
  };
  SoKeyboardEvent::Key key;
  bool isDown;
} keyboard[] = {
  { SoKeyboardEvent::UP_ARROW, false },   // array with key states
  { SoKeyboardEvent::DOWN_ARROW, false }, // usage: keyboard[KeyRec::DOWN].isDown
  { SoKeyboardEvent::LEFT_ARROW, false },
  { SoKeyboardEvent::RIGHT_ARROW, false },
};

void keyboardEvent_cb(void *userdata, SoEventCallback *node);
void simulationStep(void *data, SoSensor *sensor);

avatar* user_avatar = NULL;
SoPerspectiveCamera *camera;

int main(int argc, char **argv)
{
  
  try
    {

      SoDB::init();

      if(argc<3)
	{
	  throw std::string("Usage:\n\tL3DClient <server> <port> <avatar_name>\n");
	}

      QApplication app(argc, argv);  

      boost::asio::io_service io_service;
      boost::asio::ip::tcp::resolver resolver(io_service);
      boost::asio::ip::tcp::resolver::query query(argv[1], argv[2]);
      boost::asio::ip::tcp::resolver::iterator iterator = resolver.resolve(query);

      client c(io_service, iterator);
      
      std::string executors_name = argv[3];
      command_executor client_exec(executors_name);
      c.add_observer(&client_exec);
      
      avatar my_avatar(executors_name, c);
      user_avatar = & my_avatar;

      //start BOOST_ASIO
      boost::thread asio_th(boost::bind(&boost::asio::io_service::run, &io_service));

      if(asio_th.joinable()) {
        cout << "Detaching thread" << endl;
        asio_th.detach();
      }

      // The scene
      SoSeparator *root = new SoSeparator();
      root->ref();
      
      camera = new SoPerspectiveCamera();
      camera->nearDistance = 4;
      camera->farDistance = 4096;

      root->addChild(camera);
      root->addChild(get_scene_graph_from_file("vrml/world/world.wrl"));
      root->addChild(get_scene_graph_from_file("vrml/world/grass.wrl"));
      root->addChild(my_avatar.get3d_model());

      gui viewer(root, app, camera);
      viewer.show();


      ////////// move camera and avatar with directional keys
      
      // keyboard handling
      SoEventCallback *cb = new SoEventCallback;
      cb->addEventCallback(SoKeyboardEvent::getClassTypeId(), keyboardEvent_cb, NULL);
      root->insertChild(cb, 0);

      // sensor for infinite processing of simulationStep
      SoOneShotSensor *sensor = new SoOneShotSensor(simulationStep, NULL);
      sensor->schedule();
      
      ////////// end


      return app.exec();

    }  
  catch(std::exception &e)
    {
      std::cout<<std::endl<<e.what();
      exit(EXIT_FAILURE);
	}
  catch(std::string msg)
    {
      std::cout<<std::endl<<msg;
      exit(EXIT_FAILURE);
    }

  return EXIT_SUCCESS;
  
}


void keyboardEvent_cb(void *userdata, SoEventCallback *node)
{
  const SoEvent *event = node->getEvent();

  // handling of array keyboard
  for(int i=0; i<sizeof(keyboard)/sizeof(KeyRec); ++i)
  {
    if(SoKeyboardEvent::isKeyPressEvent(event, keyboard[i].key))
      keyboard[i].isDown=true;

    if(SoKeyboardEvent::isKeyReleaseEvent(event, keyboard[i].key))
      keyboard[i].isDown=false;
  }

  // handle ESC
  if(SoKeyboardEvent::isKeyPressEvent(event, SoKeyboardEvent::ESCAPE)) 
    {
      SoQt::exitMainLoop();
    }

  node->setHandled();
}

void updateScene(double currentTime, double deltaTime)
{

  // static double fpsTime = currentTime;
  // static int fps = 0;

  // if(fpsTime+1.0 < currentTime)
  // {
  //   ++fpsTime;
  //   printf("%i fps\n", fps);
  //   fps = 0;
  // } else
  //   ++fps;

  float speed = user_avatar->getSpeed();  // speed of user_avatar
  float orientation = user_avatar->getOrientation();
  SbVec3f originalPosition = user_avatar->getPosition();  // save current user_avatar->position

  // user_avatar->speed: acceleration
  if(keyboard[KeyRec::UP].isDown)
  {
    if(speed < maxSpeed)
    {
      speed += (float)deltaTime*speedUp;
      if(speed>maxSpeed)
        speed = maxSpeed;
    }
  }else
  {
    if(speed > 0)
    {
      speed -= (float)deltaTime*slowDown;
      if(speed<0)
        speed = 0;
    }
  }

  // user_avatar->speed: braking
  if(keyboard[KeyRec::DOWN].isDown)
  {
    if(speed > minSpeed)
    {
      speed -= (float)deltaTime*speedUp;
      if(speed < minSpeed)
        speed = minSpeed;
    }
  }else
  {
    if(speed < 0)
    {
      speed += (float)deltaTime*slowDown;
      if(speed > 0)
        speed = 0;
    }
  }

  // rotation speed: turn left
  if(keyboard[KeyRec::LEFT].isDown)
  {
    user_avatar->rotationSpeed += (float)deltaTime*rotSpeedUp;
    if(user_avatar->rotationSpeed > maxRotSpeed)
      user_avatar->rotationSpeed = maxRotSpeed;
  }else
  {
    if(user_avatar->rotationSpeed > 0)
    {
      user_avatar->rotationSpeed -= (float)deltaTime*rotSlowDown;
      if(user_avatar->rotationSpeed < 0)
        user_avatar->rotationSpeed = 0;
    }
  }

  // rotation speed: turn right
  if(keyboard[KeyRec::RIGHT].isDown)
  {
    user_avatar->rotationSpeed -= (float)deltaTime*rotSpeedUp;
    if(user_avatar->rotationSpeed < minRotSpeed)
      user_avatar->rotationSpeed = minRotSpeed;
  }else
  {
    if(user_avatar->rotationSpeed < 0)
    {
      user_avatar->rotationSpeed += (float)deltaTime*rotSlowDown;
      if(user_avatar->rotationSpeed > 0)
        user_avatar->rotationSpeed = 0;
    }
  }

  // user_avatar->orientation
  // note: negative values must be used when going back
  if(speed >= 0)
    orientation += (float)deltaTime*user_avatar->rotationSpeed;
  else
    orientation -= (float)deltaTime*user_avatar->rotationSpeed;

  // set new user_avatar->orientation
  user_avatar->setOrientation(orientation);


  // set new user_avatar->position
  float distance = speed*(float)deltaTime;
  SbVec3f pos = user_avatar->getPosition();

  SbVec3f distanceVec(distance*sinf(orientation), 0.f, distance*cosf(orientation));
  pos -= distanceVec;

  float posX = 0.0, posY = 0.0, posZ;
  pos.getValue(posX,posY,posZ);

  if (posX < -2999)
    {
       user_avatar->setSpeed(0);
    }
  else if (posX > 2999)
    {
       user_avatar->setSpeed(0);
    }
  else if (posZ < -2999)
    {
      user_avatar->setSpeed(0);
    }
  else if (posZ > 2999)
    {
      user_avatar->setSpeed(0);
    }
  else
    {

  user_avatar->setPosition(pos);
  user_avatar->direction = user_avatar->getPosition() - originalPosition;
  // set new user_avatar->speed
  user_avatar->setSpeed(speed);

    }

  if(!gui::free_camera)
    {

      // 3rd person camera
      float tilt = -.20f;          // camera tilt (in radians)
      float cameraDistance = 15;   // initial camera distance from the user_avatar
      float cameraHeight = 8.0f;  // camera height from the user_avatar

      SbRotation cameraOrientation, cameraTilt;
      cameraOrientation.setValue(SbVec3f(0, 1, 0), orientation);
      cameraTilt.setValue(SbVec3f(1, 0, 0), tilt);
      camera->orientation = cameraTilt*cameraOrientation;

      if(speed < 0)
	{
	  cameraDistance = 18.0f-speed*0.44f;  // camera distance increases when going back
	}

      SbVec3f cameraPosition(user_avatar->getPosition());
      cameraPosition += SbVec3f(cameraDistance*sinf(orientation), cameraHeight, cameraDistance*cosf(orientation));
      camera->position.setValue(cameraPosition);
      
      if(broacastPosition_timePassed >= broacastPosition_interval)
	{
	  user_avatar->broadcastPosition();
	  broacastPosition_timePassed = 0;
	}

      broacastPosition_timePassed += deltaTime;

    }

}

void simulationStep(void *data, SoSensor *sensor)
{
  // compute time from the last run of simulationStep
  static double ct = SbTime::getTimeOfDay().getValue(); // current time
  static double lt; // last time

  lt = ct;
  ct = SbTime::getTimeOfDay().getValue();
  double dt = ct - lt; // delta time

  // update scene
  updateScene(ct, dt);

  // reschedule sensor (it will make this function to be called again and again)
  sensor->schedule();
}
