#ifndef L3DCLIENT_AVATAR_H
#define L3DCLIENT_AVATAR_H

#include <string>
#include <QObject>

#include "client.h"

#include <Inventor/nodes/SoTranslation.h>
#include <Inventor/nodes/SoRotation.h>
#include <Inventor/nodes/SoSeparator.h>


class avatar : public QObject
{

  Q_OBJECT

private:

  SoSeparator* _3d_model;
  std::string _name = "";
  client* _my_client;
  int _avatar_gender = 0;
  float orientation;
  float speed;
  SoTranslation *translation;
  SoRotation *rotation;

  SbVec3f _previousPosition;

  // user is prevented from using the default constructor
  avatar();

public:

  avatar(std::string name, client& associated_server_client, int avatar_gender);
  SoSeparator* get3d_model();
  
  SbVec3f direction;
  float angleCorrection;
  void setSpeed(float v);
  float getSpeed() const;
  float rotationSpeed; 
  SbVec3f getPosition() const; 
  void getPosition(float &x, float &y, float &z) const;
  void setPosition(const SbVec3f &pozice);
  void setPosition(const float x, const float y, const float z);
  float getOrientation() const;
  void setOrientation(const float &angle);

  void broadcastPosition();

public slots:

  void chatWith(const std::string& other_name, const std::string& msg);  

};

#endif
