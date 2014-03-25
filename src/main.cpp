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
#include <Inventor/sensors/SoTimerSensor.h>
#include <QDebug>
#include <QApplication>

#define SPEED 1
#define REFRESH_TIME 0.05
#define PI 3.14

bool startMoving = false;
void update_avatar(void *, SoSensor *);
void keyboard_callback_func(void *userData, SoEventCallback *eventCB);

avatar * user_avatar = NULL;

int main(int argc, char **argv)
{


  
  try
    {

      QApplication app(argc, argv);  

      SoSeparator *world = get_scene_graph_from_file("vrml/world/world.wrl");
      // The first an third person cameras
      SoPerspectiveCamera *camera = new SoPerspectiveCamera();

      if(argc<3)
	{
	  throw std::string("Usage:\n\tL3DClient <server> <port> <avatar_name>\n");
	}

      boost::asio::io_service io_service;

      boost::asio::ip::tcp::resolver resolver(io_service);
      boost::asio::ip::tcp::resolver::query query(argv[1], argv[2]);
      boost::asio::ip::tcp::resolver::iterator iterator = resolver.resolve(query);

      client c(io_service, iterator);
      
      c.send(std::move(std::string("add 5 3")));

      std::string executors_name = argv[3];

      command_executor client_exec(executors_name);
      c.add_observer(&client_exec);
      
      avatar my_avatar(camera, c);
      user_avatar = & my_avatar;

      // The scene
      SoSeparator *root = new SoSeparator();
      // Add camera
      root->addChild(camera);
      // Add terrain
      root->addChild(world);
      root->addChild(get_scene_graph_from_file("vrml/world/grass.wrl"));
      root->addChild(my_avatar.get3d_model());

      gui viewer(root, app, camera);
      viewer.show();

      //my_avatar.show_camera_settings();

      // move camera and avatar with directional keys
      SoEventCallback *keyboard_event_callback = new SoEventCallback;
      keyboard_event_callback->addEventCallback( SoKeyboardEvent::getClassTypeId(), keyboard_callback_func, camera);
      root->addChild(keyboard_event_callback);
      SoTimerSensor *camera_time_sensor = new SoTimerSensor(update_avatar, root);
      camera_time_sensor->setInterval(SbTime(REFRESH_TIME));
      camera_time_sensor->schedule();
      // end

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

void update_avatar(void *, SoSensor *)
{
  if((user_avatar!=NULL)&&(startMoving) )
    {
      user_avatar->update_avatar();
    }
}

void keyboard_callback_func(void *userData, SoEventCallback *eventCB)
{
  
  const SoEvent *event = eventCB->getEvent();

  if (SO_KEY_PRESS_EVENT(event, UP_ARROW)) {
    if(user_avatar!=NULL)
      {
	startMoving = true;
	user_avatar->accelerate(SPEED);
      }
    eventCB->setHandled();
  } else if (SO_KEY_PRESS_EVENT(event, DOWN_ARROW)) {
    if(user_avatar!=NULL)
      {
	startMoving = true;
	user_avatar->decellerate(SPEED);
      }
    eventCB->setHandled();
  } else if(SO_KEY_PRESS_EVENT(event, LEFT_ARROW)) {
    if(user_avatar!=NULL)
      {
	startMoving = true;
	user_avatar->goto_left();
      }
    eventCB->setHandled();
  } else if(SO_KEY_PRESS_EVENT(event , RIGHT_ARROW)) {
    if(user_avatar!=NULL)
      {
	startMoving = true;
	user_avatar->goto_right();
      }
    eventCB->setHandled();
  } if(SO_KEY_PRESS_EVENT(event , RIGHT_SHIFT)) {
    if(user_avatar!=NULL)
      {
	user_avatar->stop();
	startMoving = false;
      }
    eventCB->setHandled();
    
  } 

}
