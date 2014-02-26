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
  SoCamera* _first_person_camera;
  SoCamera* _third_person_camera;

public:
  coinviewer(QWidget *parent , SoSeparator* scene, SoCamera *first_person_camera, SoCamera *third_person_camera);
};

#endif
