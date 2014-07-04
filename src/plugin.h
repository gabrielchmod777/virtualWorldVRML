#ifndef L3DCLIENT_PLUGIN_H
#define L3DCLIENT_PLUGIN_H

#include <Inventor/nodes/SoSeparator.h>
#include <QObject>

class CPlugIn : public QObject
{

private:
  SoSeparator* _3d_model = NULL;
  SoSeparator* _root = NULL;
  QObject* _obj_sig_slot = NULL;

  //CPlugIn(){};
  
public:

  CPlugIn( SoSeparator* insertionPoint, QObject* sig_slot , std::string data )
  {

    _3d_model = new SoSeparator();

    _root = insertionPoint;
    _obj_sig_slot = sig_slot;
    build_3d_model( _3d_model );
    connect_sig_slot( _obj_sig_slot );

    assert( _3d_model != NULL );
    _root->addChild( _3d_model );

  };

  virtual ~CPlugIn(){};
  virtual void connect_sig_slot( QObject* other ){};

  virtual void build_3d_model( SoSeparator* _separator ) = 0;
  virtual void exec_operation( std::string operation ) = 0;

};


extern "C" {
  CPlugIn* get_plug_in( std::string data, SoSeparator* insertionPoint, std::string name ,QObject* sig_slot );
}

#endif
