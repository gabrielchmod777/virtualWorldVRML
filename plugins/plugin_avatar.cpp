#include "../src/plugin.h"
#include "../src/vrml_utils.h"
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoTranslation.h>
#include <Inventor/nodes/SoRotation.h>
#include <Inventor/nodes/SoCone.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <sstream>

#include "../src/vrml_utils.cpp"

extern "C" void get_plug_in( std::string data, SoSeparator* insertionPoint )
{

  using boost::property_tree::ptree;
  ptree pt;

  std::stringstream streammed_msg;
  streammed_msg<<data;

  read_xml(streammed_msg, pt);

  std::string action = pt.get<std::string>("response.action");
  std::string gender = pt.get<std::string>("response.avatar_type_id");
  std::string name = pt.get<std::string>("response.other_user");
 
  std::string rotN = "MOC_ROTATE_"+name;
  std::string movN = "MOC_MOVE_"+name;
 
  //create grapichs first time only
  SoSeparator* _3d_obj = (SoSeparator*)findNode(name.c_str(),insertionPoint);

  std::cout<<std::endl<<data;
  if( _3d_obj == NULL )
    {
      std::cout<<std::endl<<"CREATE A MOC AVATAR";

      SoTranslation *translation = new SoTranslation;
      translation->translation.setValue(0.1,0,0);
      translation->setName( movN.c_str() );
      SoRotation *rotation = new SoRotation;
      rotation->rotation.setValue(SbVec3f(0, 1, 0), 0.1);
      rotation->setName( rotN.c_str() );

      _3d_obj = new SoSeparator;
      _3d_obj->setName(name.c_str());
      _3d_obj->addChild( translation );
      _3d_obj->addChild( rotation );

      if ( gender == "0" )
	{
	  _3d_obj->addChild(get_scene_graph_from_file("/usr/local/share/l3dclient/avatar_male.wrl"));
	}
      else
	{
	  _3d_obj->addChild(get_scene_graph_from_file("/usr/local/share/l3dclient/avatar_female.wrl"));
	}

      insertionPoint->addChild( _3d_obj );
    }
  //end create graphics

  //execute code for the current action
  if ( action == "rotate" )
    {
      std::string s_angle = pt.get<std::string>("response.degrees");
      float angle = std::stof( s_angle.c_str() );
      SoRotation* rotation = (SoRotation*) findNode( rotN.c_str(), insertionPoint );
      if ( rotation == NULL )
	{
	  rotation = new SoRotation;
	  rotation->setName( rotN.c_str() );
	  _3d_obj->addChild( rotation );
	}

      rotation->rotation.setValue(SbVec3f(0, 1, 0), angle);
    }
  else if ( action == "move" )
    {
      float x,z;
      
      std::string s_X = pt.get<std::string>("response.x");
      x = std::stof( s_X.c_str() );
      std::string s_Z = pt.get<std::string>("response.z");
      z = std::stof( s_Z.c_str() );
      
      //SbVec3f pos(x,y,z);
      SoTranslation* translation = (SoTranslation*) findNode( movN.c_str(), insertionPoint );
      if ( translation == NULL )
	{

	  translation = new SoTranslation;
	  translation->setName( movN.c_str() );
	  _3d_obj->addChild( translation );
      
	}
      translation->translation.setValue(x,0.0,z);
    
    }
  else if ( action == "talk" )
    {

    }


}
