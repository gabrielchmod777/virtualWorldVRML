#include "../src/plugin.h"
#include "../src/vrml_utils.h"
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoTranslation.h>
#include <Inventor/nodes/SoRotation.h>
#include <Inventor/nodes/SoCone.h>
#include <Inventor/nodes/SoFile.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <sstream>
#include <vector>
#include <QDebug>
#include <stdlib.h>
#include <pwd.h>
#include <stdio.h>

const char *getUserName()
{
  uid_t uid = geteuid();
  struct passwd *pw = getpwuid(uid);
  if (pw)
  {
    return pw->pw_name;
  }

  return "";
}

#include "../src/vrml_utils.cpp"

extern "C" void get_plug_in( std::string data, SoSeparator* insertionPoint )
{

    try
    {
      using boost::property_tree::ptree;
      ptree pt;
      std::stringstream streammed_msg;

      streammed_msg<<data;
  
      read_xml(streammed_msg, pt);

      std::string archive = pt.get<std::string>("response.raw.archive");

      std::cout<<std::endl<<"   ********************* DOWNLOAD RESOURCES ****************   ";
      std::cout<<system( "rm -r ~/.l3dclient/resources/*" );
      std::string wget_cmd = "wget -P ~/.l3dclient/resources/ "+archive;
      std::cout<<system( wget_cmd.c_str() );
      std::cout<<system( "tar -xvf ~/.l3dclient/resources/env.tar.gz -C ~/.l3dclient/resources/" );
      std::cout<<std::endl<<"   *********************************************************   ";;

      SoSeparator* sep = new SoSeparator;
      sep->ref();
      SoFile* fff = new SoFile;
      
      std::string usr = getUserName();
      std::string aFile = "/home/"+usr+"/.l3dclient/resources/env/env.wrl";
      std::cout<<std::endl<<"   *********************************************************   ";;
      std::cout<<std::endl<<"   *********************************************************   ";;
      std::cout<<std::endl<<"   *********************************************************   ";;
      std::cout<<std::endl<<aFile;
      std::cout<<std::endl<<"   *********************************************************   ";;
      std::cout<<std::endl<<"   *********************************************************   ";;
      std::cout<<std::endl<<"   *********************************************************   ";;
      fff->name.setValue(aFile.c_str());
      sep->addChild( new SoCone );
      //sep->addChild(get_scene_graph_from_file(aFile.c_str()));
      //insertionPoint->addChild( sep );

    }
    catch(const boost::property_tree::xml_parser::xml_parser_error &e)
      {
	std::cout << "Could not parse file due to " << e.what() << std::endl;
      }
    catch (const std::exception &exc)
      {
	std::cout << exc.what();
      }

}



