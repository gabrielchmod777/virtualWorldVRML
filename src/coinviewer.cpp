#include <QObject>
#include <QWidget>
#include <Inventor/Qt/SoQt.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoCamera.h>
#include "coinviewer.h"


coinviewer::coinviewer(QWidget *parent , SoSeparator* scene)
{

  SoQt::init(this);
  SoQtExaminerViewer *viewer = new SoQtExaminerViewer(this);
  viewer->setSceneGraph(scene);
  viewer->setSize(SbVec2s(1024,768));
  
  viewer->show();

}


