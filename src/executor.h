#ifndef _MCG_EXECUTOR
#define _MCG_EXECUTOR

#include <string>
#include <iostream>
#include <Inventor/nodes/SoSeparator.h>
#include <unordered_map>
#include "message_observer.h"
#include "plugin.h"

class command_executor : public message_observer
{
 private:
  SoSeparator * vrml_node;
  std::string name;
  //void execute_command(SoSeparator && model);
  command_executor();
  std::unordered_map< std::string, PLUG_IN > _plugins_map; 
 public:
  command_executor(std::string exec_name);
  virtual ~command_executor();

  void onMessageReceived(std::string message);
  void set_vrml_tree_node(SoSeparator *node);

};

#endif
