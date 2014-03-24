#include "vrmlreader.h"
#include "avatar.h"
#include <string>
#include <cmath>

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

  _position = Vec2d(100,100);
  _direction = Vec2d(1,1).normalized();
  _speed = 0; 
  _3d_model = new SoSeparator();
  _transform = new SoTransform();
  _3d_model->addChild(_transform);
  _3d_model->addChild(get_scene_graph_from_file("vrml/avatar/human.wrl"));
  //                                 X  Y  Z
  _camera->position.setValue(SbVec3f(0, 2 ,6));
  _camera->pointAt(SbVec3f(0, 0, 0 ));
  
}

void avatar::modify_camera_height_offset(int offset)
{
  _height_camera_offset = 1+(offset/10);
  _camera->position.setValue(_position.get_x(), _height_camera_offset, _position.get_y());
}

void avatar::modify_camera_distance_offset(int offset)
{
  _distance_camera_offset = 1+(offset/10);
  _camera->position.setValue(_position.get_x(), _height_camera_offset ,_distance_camera_offset);
}

void avatar::show_camera_settings()
{
  _camera_offset_dialog.show();
}

void avatar::accelerate(float increment)
{
  _speed += increment;
  if(_speed > max_speed) 
    {
      _speed = max_speed;
    }
  
}

void avatar::decellerate(float decrement)
{
  _speed -= decrement;
  if(_speed<0)
    {
      _speed = 0;
    }
}

void avatar::stop()
{
  _speed = 0;
}

void avatar::goto_left()
{
  _direction.rotate(90, Vec2d::DEGREES_360);
}

void avatar::goto_right()
{
  _direction.rotate(-90, Vec2d::DEGREES_360);
}

bool cmpf(float A, float B, float epsilon = 0.05f)

{ 

    return (fabs(A - B) < epsilon);

}

void avatar::update_avatar()
{

  float x_displacement = 0.0;
  float y_displacement = 0.0;

  _transform->rotation.setValue(SbVec3f(0,1,0), _direction.get_angle(Vec2d::DEGREES_RADIAN));
  
  float speed_correct = 0.0;
  if(cmpf((_direction.get_angle(Vec2d::DEGREES_RADIAN)),0.785398) || cmpf((_direction.get_angle(Vec2d::DEGREES_RADIAN)),-2.35619))
    {
      speed_correct = - _speed;
    }
  else
    {
      speed_correct = _speed;
    }

  Vec2d displacement = Vec2d( _direction.get_x() * speed_correct, _direction.get_y() * speed_correct ); // both * time_passed

  _position = _position + displacement;
  _transform->translation.setValue(_position.get_x(), 0, _position.get_y());

  if(cmpf((_direction.get_angle(Vec2d::DEGREES_RADIAN)),0.785398))
    {
      qDebug()<<"\n ....  +0.7 ";
      x_displacement = 6;
      y_displacement = 6;
    }
  else if( cmpf((_direction.get_angle(Vec2d::DEGREES_RADIAN)),-2.35619))
    {
      x_displacement = -6;
      y_displacement = -6;      
    }
  else if( cmpf((_direction.get_angle(Vec2d::DEGREES_RADIAN)),-0.785398))
    {
      qDebug()<<"\n ....  -0.7 ";
      x_displacement = -6;
      y_displacement = 6;
    }
  else if( cmpf((_direction.get_angle(Vec2d::DEGREES_RADIAN)),2.35619))
    {
      x_displacement = 6;
      y_displacement = -6;
    }

  
  _camera->position.setValue(SbVec3f(_position.get_x()+x_displacement, 2 , _position.get_y()+y_displacement));
  _camera->pointAt(SbVec3f(_position.get_x(), 0, _position.get_y()));

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
