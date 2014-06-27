#ifndef L3DCLIENT_LOGINDIALOG
#define L3DCLIENT_LOGINDIALOG

#include "ui_login.h"

#include <QDialog>
#include <QWidget>
#include <QObject>

class login_dialog : public QDialog, public Ui::LogInUi
{
  Q_OBJECT
public:

enum {AVATAR_MALE, AVATAR_FEMALE};

int selected_avatar = login_dialog::AVATAR_MALE;

login_dialog( QWidget* parent = 0 );
virtual ~login_dialog();

public slots:
void selectMaleAvatar();
void selectFemaleAvatar();

};

#endif
