#ifndef _MAINGUI_HH
#define _MAINGUI_HH

#include <QObject>
#include <QtGui>
#include <QApplication>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoCamera.h>
#include "ui_left_form.h"
#include "coinviewer.h"

class LeftForm : public QDialog, public Ui::leftForm
{
  //Q_OBJECT

 public:
  LeftForm(QWidget *parent = 0) : QDialog(parent){
    setupUi(this);
  };
};

class gui : public QWidget
{
  Q_OBJECT

 private:
  LeftForm *onTheRight;
  coinviewer* viewer;

 public:
  static bool free_camera;

  gui(SoSeparator* vrml_scene, QApplication & app, SoCamera* camera);
  
 public slots:
  void toggle_free_camera_onoff(bool b);

};

#endif
