#ifndef L3DCLIENT_AVATAR_H
#define L3DCLIENT_AVATAR_H

#include <string>
#include <QObject>
#include <QDialog>
#include <QWidget>
#include <Inventor/nodes/SoTransform.h>
#include <Inventor/nodes/SoCamera.h>

#include "vector2f.h"
#include "client.h"

#include "ui_camerapositioning_dialog.h"

class Ui_Camera : public QDialog, public Ui::CameraPositionDialog
{
  Q_OBJECT

 public:
  Ui_Camera(QWidget *parent = 0) : QDialog(parent){
    setupUi(this);
  };
};


class avatar : public QObject
{

  Q_OBJECT

private:

  static const float max_speed;

  double _speed;

  Vec2d _position;
  Vec2d _direction;

  SoSeparator* _3d_model;
  SoTransform* _transform;

  std::string name;

  float _height_camera_offset;
  float _distance_camera_offset;

  SoCamera* _camera;
  Ui_Camera _camera_offset_dialog;

  client* _my_client;

  // user is prevented from using the default constructor
  avatar();

public:
  avatar(SoCamera * camera, client& associated_server_client);
  void show_camera_settings();
  void accelerate(float increment); 
  void decellerate(float decrement);
  void stop();
  void goto_left();
  void goto_right();
  void update_avatar();
  SoSeparator* get3d_model();

public slots:
  void modify_camera_height_offset(int offset);
  void modify_camera_distance_offset(int offset);

};

#endif
