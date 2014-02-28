#ifndef COIN_VIEWER_HH
#define COIN_VIEWER_HH

#include <QWidget>
#include <QObject>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoCamera.h>

class coinviewer : public QWidget
{
  Q_OBJECT

private:
  SoCamera* _camera;

public:
  coinviewer(QWidget *parent , SoSeparator* scene, SoCamera * camera);
};

#endif
