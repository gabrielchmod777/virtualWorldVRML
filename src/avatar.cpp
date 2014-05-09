#include "vrmlreader.h"
#include "avatar.h"
#include "client.h"

#include <string>

#include <Inventor/nodes/SoTranslation.h>
#include <Inventor/nodes/SoRotation.h>
#include <Inventor/nodes/SoSeparator.h>


avatar::avatar()
{
  // PRIVATE: can not use the default constructor; 
}

avatar::avatar(client& associated_server_client)
{

  _my_client = &associated_server_client;

  speed = 0;
  rotationSpeed = 0;
  orientation = 0;

  _3d_model = new SoSeparator();

  this->translation = new SoTranslation;
  this->_3d_model->addChild(this->translation);

  this->rotation = new SoRotation;
  this->_3d_model->addChild(this->rotation);

  _3d_model->addChild(get_scene_graph_from_file("vrml/avatar/human.wrl"));

}

SoSeparator* avatar::get3d_model()
{
  return _3d_model;
}

void avatar::setSpeed(float v)
{ 
  speed=v; 
}

float avatar::getSpeed() const 
{ 
  return speed; 
}

SbVec3f avatar::getPosition() const 
{ 
  return translation->translation.getValue(); 
}

void avatar::getPosition(float &x, float &y, float &z) const 
{ 
  translation->translation.getValue().getValue(x, y, z); 
}

void avatar::setPosition(const SbVec3f &pozice)
{ 
  translation->translation.setValue(pozice); 
}

void avatar::setPosition(const float x, const float y, const float z) 
{ 
  translation->translation.setValue(x, y, z); 
}

float avatar::getOrientation() const 
{ 
  return orientation; 
}

void avatar::setOrientation(const float &angle)
{ 
  orientation=angle;
  rotation->rotation.setValue(SbVec3f(0, 1, 0), angle); 
}
