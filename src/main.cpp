#include "vrmlreader.h"
#include "gui.h"

#include <cstdlib>
#include <memory>
#include <iostream>
#include <unistd.h>

#include <Inventor/Qt/SoQt.h>         
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>  
#include <Inventor/SoDB.h>         
#include <Inventor/errors/SoDebugError.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoNode.h>
#include <Inventor/nodes/SoTransform.h>
#include <Inventor/nodes/SoText3.h>
#include <Inventor/nodes/SoMaterial.h>

#include <QApplication>


int main(int argc, char **argv)
{

  QApplication app(argc, argv);

  SoSeparator *terrain = get_scene_graph_from_file("vrml/world/world.wrl");
  
  // The scene
  SoSeparator *root = new SoSeparator();
  // Add terrain
  root->addChild(terrain);
  root->addChild(get_scene_graph_from_file("vrml/buildings/greek_museum/greek_museum.wrl"));
  root->addChild(get_scene_graph_from_file("vrml/world/grass.wrl"));
  root->addChild(get_scene_graph_from_file("vrml/avatar/human.wrl"));

  gui viewer(root, app);
  viewer.show();

  return app.exec();
}



/********
#include <Inventor/Qt/SoQt.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/nodes/SoGroup.h>

int main(int , char **argv)
{
   // Initialize Inventor and Xt
   QWidget * myWindow = SoQt::init(argv[0]);
   if (myWindow == NULL) exit(1);

   SoSeparator *root = new SoSeparator;
   root->ref();

   // This function contains our code fragment.
   root->addChild(get_scene_graph_from_file("vrml/world/world.wrl"));
   root->addChild(get_scene_graph_from_file("vrml/buildings/greek_museum/greek_museum.wrl"));
   root->addChild(get_scene_graph_from_file("vrml/avatar/human.wrl"));

   SoQtExaminerViewer *myViewer = 
            new SoQtExaminerViewer(myWindow);
   myViewer->setSceneGraph(root);
   myViewer->setTitle("L3DClient");
   myViewer->show();
   myViewer->viewAll();

   SoQt::show(myWindow);
   SoQt::mainLoop();

   delete myViewer;
   root->unref();

   return 0;
}
*/
