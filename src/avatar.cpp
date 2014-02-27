
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

avatar::avatar(SoCamera * first_person_camera, SoCamera * third_person_camera)
{
  _first_person_camera = first_person_camera;
  _third_person_camera = third_person_camera;

  QObject::connect(_first_person_camera_pos_dialog.x_position, SIGNAL(valueChanged(int)), this, SLOT(modify_camera_x_position(int)));
}

void avatar::modify_camera_x_position(int offset)
{
  qDebug()<< " cam _ x _ "<<offset;
}

void avatar::modify_camera_z_position(int offset)
{
  qDebug()<< " cam _ z _ "<<offset;
}

void avatar::show_first_person_camera_settings()
{
  _first_person_camera_pos_dialog.show();
}

void avatar::show_third_person_camera_settings()
{
  _third_person_camera_pos_dialog.show();
}
