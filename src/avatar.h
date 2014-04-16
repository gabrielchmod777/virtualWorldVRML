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

class avatar : public QObject
{

  Q_OBJECT

private:

  static const float max_speed;

  double _speed;

  float previous_x_position;
  float previous_y_position;

  Vec2d _position;
  Vec2d _direction;

  SoSeparator* _3d_model;
  SoTransform* _transform;

  std::string name;

  float _height_camera_offset;
  float _distance_camera_offset;

  SoCamera* _camera;

  client* _my_client;

  // user is prevented from using the default constructor
  avatar();

public:
  avatar(SoCamera * camera, client& associated_server_client);
  void accelerate(float increment); 
  void decellerate(float decrement);
  void stop();
  void goto_left();
  void goto_right();
  void update_avatar();
  SoSeparator* get3d_model();

};

#endif
