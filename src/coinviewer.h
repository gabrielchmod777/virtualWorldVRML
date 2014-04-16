#ifndef COIN_VIEWER_HH
#define COIN_VIEWER_HH

#include <QWidget>
#include <QObject>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoCamera.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>

class coinviewer : public QWidget
{
  Q_OBJECT

private:
  SoCamera* _camera;
  SoQtExaminerViewer *viewer;
public:
  coinviewer(QWidget *parent , SoSeparator* scene, SoCamera * camera);
  void setViewing(bool mode);
};

#endif
