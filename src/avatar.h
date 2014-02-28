#ifndef L3DCLIENT_AVATAR_H
#define L3DCLIENT_AVATAR_H

#include <QObject>
#include <QDialog>
#include <QWidget>
#include <Inventor/nodes/SoCamera.h>
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
  float _height_camera_offset;
  float _distance_camera_offset;

  SoCamera* _camera;
  Ui_Camera _camera_offset_dialog;

  // user is prevented from using the default constructor
  avatar();

public:
  avatar(SoCamera * camera);
  void show_camera_settings();

public slots:
  void modify_camera_height_offset(int offset);
  void modify_camera_distance_offset(int offset);

};

#endif
