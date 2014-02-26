#ifndef _MAINGUI_HH
#define _MAINGUI_HH

#include <QObject>
#include <QtGui>
#include <QApplication>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoCamera.h>

class gui : public QWidget
{
  Q_OBJECT

 public:
  gui(SoSeparator* vrml_scene, QApplication & app, SoCamera* first_person_camera, SoCamera* third_person_camera);
  
};

#endif
