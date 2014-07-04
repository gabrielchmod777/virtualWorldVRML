#include "../src/plugin.h"
#include "../src/vrml_utils.h"
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoCone.h>
#include <string>
#include <iostream>


#include "../src/vrml_utils.cpp"

extern "C" void get_plug_in( std::string data, SoSeparator* insertionPoint )
{

  SoSeparator* _3d_obj = (SoSeparator*)findNode("other",insertionPoint);



  std::cout<<std::endl<<"      PLUG IN      ";
  std::cout<<std::endl<<data;
  if( _3d_obj == NULL )
    {
      std::cout<<std::endl<<"CREATE A CONE";
      _3d_obj = new SoSeparator;
      _3d_obj->setName("other");
      _3d_obj->addChild( new SoCone );
      insertionPoint->addChild( _3d_obj );
    }
  else 
    {
      std::cout<<std::endl<<"CONE EXISTS";
    }
  
}
