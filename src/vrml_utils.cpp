#include "vrml_utils.h"
#include <set>
#include <iostream>
#include <Inventor/SoDB.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/SoInteraction.h>
#include <Inventor/SoInput.h>
#include <Inventor/SoOutput.h>
#include <Inventor/actions/SoWriteAction.h>
#include <Inventor/actions/SoToVRML2Action.h>
#include <Inventor/actions/SoSearchAction.h>
#include <Inventor/VRMLnodes/SoVRMLGroup.h>
#include <Inventor/SoLists.h>
#include <Inventor/misc/SoNotification.h>


SoSeparator* get_scene_graph_from_file(const char* filename)
{

  SoInput scene_input;

  if (!scene_input.openFile(filename)) {
    std::cout<<std::endl<<"Can not open file: "<<filename;
    return NULL;
  }
    
  SoSeparator *graph = SoDB::readAll(&scene_input);
  if (graph == NULL) {
    std::cout<<std::endl<<"Can not read from file: %s"<<filename;
    return NULL;
  }

  scene_input.closeFile();

  return graph;

}

void write_vrml_to_file(std::string pathAndFile, SoNode* scene)
{


  SoInteraction::init();

  SoToVRML2Action tovrml2;
  tovrml2.apply( scene );
  SoVRMLGroup *new_root = tovrml2.getVRML2SceneGraph();
  new_root->ref();

  SoOutput out;
  out.openFile( pathAndFile.c_str() );
  out.setHeaderString("#VRML V2.0 utf8");
  SoWriteAction wra( &out );
  wra.apply( new_root );

  new_root->unref();

}

SoNode* findNode( const char * name, SoNode* scene )
{

  static SoSearchAction * searcher = NULL;
  if ( ! searcher )
  searcher = new SoSearchAction;
  searcher->setName(SbName(name));
  searcher->setFind(SoSearchAction::NAME);
  searcher->setInterest(SoSearchAction::FIRST);
  searcher->apply(scene);
  if ( ! searcher->isFound() )
    return NULL;
  return searcher->getPath()->getTail();

}

void buildHeadNodesList(SoNode* node, std::set<SoNode*>& nodelist)
{
  if (node != NULL)
    {
      SoAuditorList* al = (SoAuditorList*)&(node->getAuditors());
      int j;
      int numParent = 0;
      for ( j = 0; j < al->getLength(); j++ )
	{
	  if (al->getType(j) == SoNotRec::PARENT)
	    {
	      SoNode* parentNode = (SoNode*)(al->getObject(j));
	      if (parentNode != NULL)
		{
		  buildHeadNodesList(parentNode, nodelist);
		  numParent++;
		}
	    }
	}
      if (numParent == 0)
	nodelist.insert(node);
    }
}
