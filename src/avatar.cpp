
#include "avatar.h"
#include <Inventor/nodes/SoCamera.h>

avatar::avatar()
{
  // PRIVATE: can not use the default constructor; 
}

avatar::avatar(SoCamera * first_person_camera, SoCamera * third_person_camera)
{
  _first_person_camera = first_person_camera;
  _third_person_camera = third_person_camera;
}
