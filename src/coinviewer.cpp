#include <QObject>
#include <QWidget>
#include <Inventor/Qt/SoQt.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoCamera.h>
#include "coinviewer.h"


coinviewer::coinviewer(QWidget *parent , SoSeparator* scene , SoCamera *first_person_camera, SoCamera *third_person_camera)
{

  _first_person_camera = first_person_camera;
  _third_person_camera = third_person_camera;

  SoQt::init(this);
  SoQtExaminerViewer *viewer = new SoQtExaminerViewer(this);
  
  viewer->setSceneGraph(scene);
  viewer->setSize(SbVec2s(1024,768));
  viewer->setViewing(FALSE);
  viewer->setCamera(_first_person_camera);
  
  viewer->show();

}


