/********************************************************************************
** Form generated from reading UI file 'left_form.ui'
**
** Created: Wed Apr 16 20:24:59 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEFT_FORM_H
#define UI_LEFT_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_leftForm
{
public:
    QPushButton *cameraPushButton;

    void setupUi(QWidget *leftForm)
    {
        if (leftForm->objectName().isEmpty())
            leftForm->setObjectName(QString::fromUtf8("leftForm"));
        leftForm->resize(291, 609);
        cameraPushButton = new QPushButton(leftForm);
        cameraPushButton->setObjectName(QString::fromUtf8("cameraPushButton"));
        cameraPushButton->setGeometry(QRect(80, 10, 121, 51));

        retranslateUi(leftForm);

        QMetaObject::connectSlotsByName(leftForm);
    } // setupUi

    void retranslateUi(QWidget *leftForm)
    {
        leftForm->setWindowTitle(QApplication::translate("leftForm", "Form", 0, QApplication::UnicodeUTF8));
        cameraPushButton->setText(QApplication::translate("leftForm", "CAMERA MODE", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class leftForm: public Ui_leftForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFT_FORM_H
