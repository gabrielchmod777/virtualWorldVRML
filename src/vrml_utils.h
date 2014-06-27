#ifndef L3DCLIENT_VRML_UTILS
#define L3DCLIENT_VRML_UTILS

#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoNode.h>
#include <Inventor/SoLists.h>
#include <Inventor/misc/SoNotification.h>
#include <string>
#include <set>

void write_vrml_to_file( std::string pathAndFile, SoNode *scene );
SoSeparator* get_scene_graph_from_file( const char* filename );
SoNode* findNode( const char * name, SoNode* scene );
void buildHeadNodesList(SoNode* node, std::set<SoNode*>& nodelist);

#endif
