/********************************************************************************
** Form generated from reading UI file 'left_form.ui'
**
** Created: Sat Jun 14 09:23:34 2014
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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_leftForm
{
public:
    QWidget *gridLayoutWidget;

    void setupUi(QWidget *leftForm)
    {
        if (leftForm->objectName().isEmpty())
            leftForm->setObjectName(QString::fromUtf8("leftForm"));
        leftForm->resize(94, 625);
        leftForm->setMaximumSize(QSize(94, 16777215));
        gridLayoutWidget = new QWidget(leftForm);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 71, 31));

        retranslateUi(leftForm);

        QMetaObject::connectSlotsByName(leftForm);
    } // setupUi

    void retranslateUi(QWidget *leftForm)
    {
        leftForm->setWindowTitle(QApplication::translate("leftForm", "Form", 0, QApplication::UnicodeUTF8));
        gridLayoutWidget->setText(QApplication::translate("leftForm", "CAMERA", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class leftForm: public Ui_leftForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFT_FORM_H
