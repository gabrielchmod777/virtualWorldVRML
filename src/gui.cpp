#include "gui.h"
#include "coinviewer.h"

#include <QObject>
#include <QtGui>
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QDebug>
#include <Inventor/nodes/SoSeparator.h>

gui::gui(SoSeparator* vrml_scene, QApplication & app, SoCamera* first_person_camera, SoCamera* third_person_camera)
{
  QVBoxLayout* all = new QVBoxLayout(this);

  QGridLayout* grid = new QGridLayout(this);
  QVBoxLayout* left = new QVBoxLayout(this);
  QVBoxLayout* right = new QVBoxLayout(this);
  
  grid->addLayout(left,0,1, 0, 1 );
  grid->addLayout(right, 0,2, 2, 1);
  grid->setColumnStretch(1, 30);
  grid->setColumnStretch(2, 10);

  coinviewer* viewer = new coinviewer(this, vrml_scene, first_person_camera, third_person_camera);
  viewer->resize(740,740);
  left->addWidget(viewer);
  this->resize(1024,768);

  all->addLayout(grid);
}
