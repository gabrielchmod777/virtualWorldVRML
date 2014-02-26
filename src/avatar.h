#ifndef L3DCLIENT_AVATAR_H
#define L3DCLIENT_AVATAR_H

#include <QObject>
#include <Inventor/nodes/SoCamera.h>

class avatar : public QObject
{

  Q_OBJECT

private:
  SoCamera * _first_person_camera;
  SoCamera * _third_person_camera;
  avatar();

public:
  avatar(SoCamera * first_person_camera, SoCamera * third_person_camera);
};

#endif
