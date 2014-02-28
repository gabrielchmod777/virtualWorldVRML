#include "vrmlreader.h"
#include "gui.h"
#include "avatar.h"

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
#include <Inventor/nodes/SoPerspectiveCamera.h>
#include <Inventor/nodes/SoCamera.h>

#include <QApplication>


int main(int argc, char **argv)
{

  QApplication app(argc, argv);

  SoSeparator *world = get_scene_graph_from_file("vrml/world/world.wrl");
  // The first an third person cameras
  SoPerspectiveCamera *camera = new SoPerspectiveCamera();
  
  avatar my_avatar(camera);

  // The scene
  SoSeparator *root = new SoSeparator();
  // Add camera
  root->addChild(camera);
  // Add terrain
  root->addChild(world);
  root->addChild(get_scene_graph_from_file("vrml/world/grass.wrl"));
  root->addChild(get_scene_graph_from_file("vrml/avatar/human.wrl"));

  gui viewer(root, app, camera);
  viewer.show();

  my_avatar.show_camera_settings();

  return app.exec();
}
