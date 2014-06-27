#include "login_dialog.h"

#include <QDialog>
#include <QWidget>

login_dialog::login_dialog( QWidget* parent) : QDialog( parent )
{
  setupUi( this );
  QObject::connect( pushButton_female, SIGNAL( clicked() ), this, SLOT( selectFemaleAvatar() ) );
  QObject::connect( pushButton_male, SIGNAL( clicked() ), this, SLOT( selectMaleAvatar() ) );
}

login_dialog::~login_dialog()
{
}

void login_dialog::selectMaleAvatar()
{
  selected_avatar = login_dialog::AVATAR_MALE;
}

void login_dialog::selectFemaleAvatar()
{

  selected_avatar = login_dialog::AVATAR_FEMALE;
  
}
