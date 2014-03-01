#include "vrmlreader.h"
#include "avatar.h"
#include <string>
#include <Inventor/nodes/SoCamera.h>
#include <Inventor/nodes/SoTransform.h>
#include <QDebug>
#include <QObject>
#include <QtCore>
#include <QSlider>

#ifndef PI
#define PI 3.1415926535
#endif

#define SPEED_INCREMENT 2
#define WORLD_LIMITS 2000

/* Helper function */
double degToRadian(double deg) 
{
  return (deg*PI)/180;
}


const float avatar::rotation_speed = 4;
const float avatar::max_speed = 14;


avatar::avatar()
{
  // PRIVATE: can not use the default constructor; 
}

avatar::avatar(SoCamera * camera)
{
  _camera = camera;

  QObject::connect(_camera_offset_dialog.x_position, SIGNAL(valueChanged(int)), this, SLOT(modify_camera_height_offset(int)));
  QObject::connect(_camera_offset_dialog.z_position, SIGNAL(valueChanged(int)), this, SLOT(modify_camera_distance_offset(int)));
  
  x = 0; y = 0;
  speed = 0; rotation = 0;
  _3d_model = new SoSeparator();
  transform = new SoTransform();
  _3d_model->addChild(transform);
  _3d_model->addChild(get_scene_graph_from_file("vrml/avatar/human.wrl"));
  look_at_x = 0;
  look_at_y = 0;
  //                                 X  Y  Z
  _camera->position.setValue(SbVec3f(x, 2 ,6));
  _camera->pointAt(SbVec3f(0, 0, 0 ));
  
}

void avatar::modify_camera_height_offset(int offset)
{
  _height_camera_offset = 1+(offset/10);
  qDebug()<< " cam _ x _ "<<_height_camera_offset;
  _camera->position.setValue(x, _height_camera_offset, y);
}

void avatar::modify_camera_distance_offset(int offset)
{
  _distance_camera_offset = 1+(offset/10);
  qDebug()<< " cam _ z _ "<<_distance_camera_offset;
  _camera->position.setValue(x, _height_camera_offset ,_distance_camera_offset);
}

void avatar::show_camera_settings()
{
  _camera_offset_dialog.show();
}

void avatar::accelerate(float increment)
{
  speed += increment;
  if(speed > max_speed) 
    {
      speed = max_speed;
    }
  
}

void avatar::decellerate(float decrement)
{
  speed -= decrement;
  if(speed<0)
    {
      speed = 0;
    }
}

void avatar::stop()
{
  speed = 0;
}

void avatar::goto_left()
{
  if(speed == 0)
    {
      speed += SPEED_INCREMENT;
    }
  rotation -= rotation_speed;
}

void avatar::goto_right()
{
  if(speed == 0)
    {
      speed += SPEED_INCREMENT;
    }
  rotation += rotation_speed;
}

void avatar::update_avatar()
{

  if(speed != 0) {
    if(rotation > 360) 
      {
	rotation -= 360;
      }

    if(rotation <0 )
      {
	rotation += 360;
      }
    rotation = 0;

    double  delta_x = cos(degToRadian(rotation))*speed;
    double  delta_y = sin(degToRadian(rotation))*speed;

    x = x+delta_x;
    y = y+delta_y;
    /*
    //update on server
    std::string cmd = " @js_eval_world var me = new avatar('a'); ";
    
    std::string str_move_command_head = "me.move('"+name+"',";
    std::string str_move_command_tail = ")\n";
    std::string str_x = std::to_string(x);
    std::string str_y = std::to_string(y);
    std::string coma = ",";
    std::string str_coord = str_x+coma+str_y;

    std::string cmd_step2 = str_move_command_head+str_x+coma+str_y+str_move_command_tail;
    cmd+= cmd_step2;

    //std::cout<<std::endl<<"DEBUG ... "<<cmd;

    my_client->send(std::move(cmd));
    */

    if(x > WORLD_LIMITS){ x = -WORLD_LIMITS; }
    if(x < -WORLD_LIMITS){ x = WORLD_LIMITS; }
    if(y > WORLD_LIMITS){ y = -WORLD_LIMITS; }
    if(y < -WORLD_LIMITS){ y = WORLD_LIMITS; }


    look_at_x = x+delta_x;
    look_at_y = y+delta_y;

    _camera->position.setValue(SbVec3f(x, 2 , y+6));
    _camera->pointAt(SbVec3f(x, 0, y ));
  
    transform->translation.setValue(x, 0, y);
    //transform->rotation.setValue(SbVec3f(0,1,0), ro);
    
    //std::cout<<std::endl<<x<<" / "<<y;

  }

}

SoSeparator* avatar::get3d_model()
{
  return _3d_model;
}
