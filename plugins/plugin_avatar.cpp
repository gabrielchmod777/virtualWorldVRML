#include "../src/plugin.h"
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoCone.h>
#include <QObject>
#include <QDebug>
#include <string>

class MocAvatar : public CPlugIn
{
  Q_OBJECT

  public:

  MocAvatar( SoSeparator* insertionPoint, QObject* sig_slot, std::string data ) : CPlugIn ( insertionPoint, sig_slot, data )
  {
    qDebug()<<"MOC_AVATAR XML : "<<data.c_str()<<"\n";
  }

  void connect_sig_slot( QObject* other ){
    qDebug()<<" .... plg ... connect";
  }

  void build_3d_model( SoSeparator* _separator )
  {
    assert( _separator != NULL );
    SoCone* mdl = new SoCone;
    _separator->addChild( mdl );
  }

  void exec_operation( std::string operation )
  {
    qDebug()<<"...... do ....OP...... : "<<operation.c_str();
  }

};

extern "C" {
  CPlugIn* get_plug_in( std::string data, SoSeparator* insertionPoint, std::string name ,QObject* sig_slot )
  {
    return (new MocAvatar(insertionPoint, sig_slot, data) );
  }
}
