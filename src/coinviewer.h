#ifndef COIN_VIEWER_HH
#define COIN_VIEWER_HH

#include <QWidget>
#include <QObject>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoCamera.h>

class coinviewer : public QWidget
{
  Q_OBJECT
public:
  coinviewer(QWidget *parent , SoSeparator* scene);
};

#endif
