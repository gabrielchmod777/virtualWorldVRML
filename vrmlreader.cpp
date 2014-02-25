#include "vrmlreader.h"

#include <iostream>
#include <Inventor/SoDB.h>
#include <Inventor/SoInput.h>
#include <Inventor/nodes/SoSeparator.h>


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

