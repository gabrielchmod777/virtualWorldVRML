#include "vrmlreader.h"
#include "avatar.h"
#include <string>
#include <Inventor/nodes/SoCamera.h>
#include <Inventor/nodes/SoTransform.h>
#include <QDebug>
#include <QObject>
#include <QtCore>
#include <QSlider>
#include <QString>

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

  position = Vec2d(0,0);
  direction = Vec2d(1,1).normalized();
  speed = 0; 
  _3d_model = new SoSeparator();
  transform = new SoTransform();
  _3d_model->addChild(transform);
  _3d_model->addChild(get_scene_graph_from_file("vrml/avatar/human.wrl"));
  //                                 X  Y  Z
  _camera->position.setValue(SbVec3f(0, 2 ,6));
  _camera->pointAt(SbVec3f(0, 0, 0 ));
  
}

void avatar::modify_camera_height_offset(int offset)
{
  _height_camera_offset = 1+(offset/10);
  _camera->position.setValue(position.get_x(), _height_camera_offset, position.get_y());
}

void avatar::modify_camera_distance_offset(int offset)
{
  _distance_camera_offset = 1+(offset/10);
  _camera->position.setValue(position.get_x(), _height_camera_offset ,_distance_camera_offset);
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
  direction.rotate(10, Vec2d::DEGREES_360);
}

void avatar::goto_right()
{
  direction.rotate(-10, Vec2d::DEGREES_360);
}

void avatar::update_avatar()
{

  

  //_camera->position.setValue(SbVec3f(position.get_x(), 2 , position.get_y()+6));
  //_camera->pointAt(SbVec3f(position.get_x(), 0, position.get_y() ));
  
  //qDebug()<<"\n .... Before ...";
  //qDebug()<<"\n .... POS = "<<QString::fromStdString(position.to_string());
  //qDebug()<<"\n .... DIR = "<<QString::fromStdString(direction.to_string());
  transform->rotation.setValue(SbVec3f(0,1,0), direction.get_angle(Vec2d::DEGREES_RADIAN));
  Vec2d displacement = Vec2d( direction.get_x() * speed, direction.get_y() * speed ); // both * time_passed
  position = position + displacement;
  transform->translation.setValue(position.get_x(), 0, position.get_y());
  if(!direction.non_zero())
    {
      qDebug()<<"\n .... Zero direction ...";
    }
  //qDebug()<<"\n .... POS = "<<QString::fromStdString(position.to_string());
  //qDebug()<<"\n .... DIR = "<<QString::fromStdString(direction.to_string());

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

    
    //std::cout<<std::endl<<x<<" / "<<y;

}

SoSeparator* avatar::get3d_model()
{
  return _3d_model;
}
