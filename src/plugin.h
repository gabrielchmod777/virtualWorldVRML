#ifndef L3DCLIENT_PLUGIN_H
#define L3DCLIENT_PLUGIN_H

#include <Inventor/nodes/SoSeparator.h>
#include <string>
 
extern "C" void get_plug_in( std::string data, SoSeparator* insertionPoint );

typedef void (*PLUG_IN)( std::string , SoSeparator*);

#endif
