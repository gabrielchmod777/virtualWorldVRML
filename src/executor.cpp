#include "executor.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include "plugin.h"
#include <QObject>
#include <QDebug>

#include <Inventor/nodes/SoSeparator.h>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/filesystem.hpp>

#define NO_PLUGIN_FOUND "ro.utcluj.aut.nopluginfound"

using namespace std;
using namespace boost::filesystem;

//typedef void (*executor_plugin)(std::string, SoSeparator *);

string decode_response_utf8(string &SRC) {
    string ret;
    char ch;
    int i, ii;
    for (i=0; i<SRC.length(); i++) {
        if (int(SRC[i])==37) {
            sscanf(SRC.substr(i+1,2).c_str(), "%x", &ii);
            ch=static_cast<char>(ii);
            ret+=ch;
            i=i+2;
        } else if(int(SRC[i])==43) {
	    ret+=" ";
	} else {
            ret+=SRC[i];
        }
    }
    return (ret);
}



struct plugin_info
{

  std::string plugin_name;
  std::string plugin_source;
 
  void read(std::stringstream & is);

};

void plugin_info::read( std::stringstream & is )
{

  using boost::property_tree::ptree;
  ptree pt;

  read_xml(is, pt);

  plugin_name = pt.get<std::string>("response.client_plugin");
  plugin_source = pt.get<std::string>("response.client_plugin_source");
  
}

std::string select_execution_plugin(std::string message, std::string & source)
{

  try
    {
      plugin_info p;
      stringstream streammed_msg;
      streammed_msg<<message;
      p.read(streammed_msg);
      
      std::cout<<std::endl<<"PLUGIN "<<p.plugin_name<<std::endl<<" SOURCE "<<p.plugin_source<<std::endl;
      source = p.plugin_source;

      return p.plugin_name;
      
    }
  catch(std::exception &e)
    {
      std::cout<<std::endl<<e.what()<<std::endl;
      return NO_PLUGIN_FOUND;
    }

  
  return NO_PLUGIN_FOUND;
}



command_executor::command_executor() 
{

}

command_executor::command_executor(std::string exec_name) 
{
  name = exec_name;
  vrml_node = NULL;

}

command_executor::~command_executor()
{
}


void command_executor::set_vrml_tree_node(SoSeparator *node)
{
  vrml_node = node;
}

#define FILE_FOUND_BY_EXTRNAL_APP 0

void loadNewPlugIn( std::string fileAndPath, std::string message, SoSeparator* vrml_node )
{
  	  void *handle;
	  PLUG_IN PLF;
	  char *error;

	  handle = dlopen (fileAndPath.c_str(), RTLD_LAZY);
	  if (!handle) {
	    fputs (dlerror(), stderr);
	    exit(1);
	  }

	  PLF = (PLUG_IN)dlsym(handle, "get_plug_in");
	  if ((error = dlerror()) != NULL)  {
	    fputs(error, stderr);
	    exit(1);
	  }

	  (*PLF)(decode_response_utf8(message), vrml_node);

	  dlclose(handle);

}

void command_executor::onMessageReceived(std::string message)
{
  std::cout<<std::endl<<decode_response_utf8(message);
  std::string src_plugin_ ="";
  std::string plug_in_name = select_execution_plugin(decode_response_utf8(message), src_plugin_);
  std::string fileAndPath = "/home/wrk/.l3dclient/plugins/"+plug_in_name;
  std::string FIND = "BOOSTFINDUTIL "+fileAndPath;  

  const char* fp = FIND.c_str();
  int found = system(fp);
  
  if ( found == FILE_FOUND_BY_EXTRNAL_APP )
    {
      if(plug_in_name != NO_PLUGIN_FOUND)
	{

	  loadNewPlugIn( fileAndPath, message, vrml_node );
      
	}

    }
  else 
    {

      std::cout<<std::endl<<"****** TRY TO DOWNLOAD *******"<<std::endl
	       <<src_plugin_
	       <<std::endl<<"******************************"<<std::endl;
  
      std::string wget_cmd = "wget -P ~/.l3dclient/plugins/ "+src_plugin_; 
      std::system(wget_cmd.c_str());

      return;
    }

}


