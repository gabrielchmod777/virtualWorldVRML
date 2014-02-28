
#include "avatar.h"
#include <Inventor/nodes/SoCamera.h>
#include <QDebug>
#include <QObject>
#include <QtCore>
#include <QSlider>

avatar::avatar()
{
  // PRIVATE: can not use the default constructor; 
}

avatar::avatar(SoCamera * camera)
{
  _camera = camera;

  QObject::connect(_camera_offset_dialog.x_position, SIGNAL(valueChanged(int)), this, SLOT(modify_camera_height_offset(int)));
  QObject::connect(_camera_offset_dialog.z_position, SIGNAL(valueChanged(int)), this, SLOT(modify_camera_distance_offset(int)));
}

void avatar::modify_camera_height_offset(int offset)
{
  _height_camera_offset = 1+(offset/10);
  qDebug()<< " cam _ x _ "<<_height_camera_offset;
  _camera->position.setValue(0.0, _height_camera_offset, 0.0);
}

void avatar::modify_camera_distance_offset(int offset)
{
  _distance_camera_offset = 1+(offset/10);
  qDebug()<< " cam _ z _ "<<_distance_camera_offset;
  _camera->position.setValue(0.0, 0.0,_distance_camera_offset);
}

void avatar::show_camera_settings()
{
  _camera_offset_dialog.show();
}


