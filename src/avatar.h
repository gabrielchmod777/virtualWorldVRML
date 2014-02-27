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
  SoCamera * _first_person_camera;
  SoCamera * _third_person_camera;
  Ui_Camera _first_person_camera_pos_dialog;
  Ui_Camera _third_person_camera_pos_dialog;
  avatar();

public:
  avatar(SoCamera * first_person_camera, SoCamera * third_person_camera);
  void show_first_person_camera_settings();
  void show_third_person_camera_settings();  
public slots:
  void modify_camera_x_position(int offset);
  void modify_camera_z_position(int offset);

};

#endif
