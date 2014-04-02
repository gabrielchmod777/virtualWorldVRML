#include <QObject>
#include <QWidget>
#include <QtGui/QApplication>
#include <QtOpenGL/QGLWidget>
#include <Inventor/Qt/SoQt.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoCamera.h>
#include "coinviewer.h"

coinviewer::coinviewer(QWidget *parent , SoSeparator* scene , SoCamera *camera)
{

  _camera = camera;

  SoQt::init(this);
  SoQtExaminerViewer *viewer = new SoQtExaminerViewer(this);
  
  /* antialiasing (three passes improves the graphics) */
  
  QGLWidget* qglw = (QGLWidget*) viewer->getGLWidget();
  QGLFormat fmt = qglw->format();

  fmt.setSampleBuffers(true);
  fmt.setSamples(3);
  qglw->setFormat(fmt);
  qglw->makeCurrent();
  glEnable(GL_MULTISAMPLE);

  /* end */
  
  viewer->setSceneGraph(scene);
  viewer->setSize(SbVec2s(1024,768));
  viewer->setViewing(FALSE);
  viewer->setCamera(_camera);
  
  viewer->show();

}
