#include "vrmlreader.h"
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
