/********************************************************************************
** Form generated from reading UI file 'left_form.ui'
**
** Created: Tue May 13 13:33:29 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEFT_FORM_H
#define UI_LEFT_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_leftForm
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *cameraPushButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *leftForm)
    {
        if (leftForm->objectName().isEmpty())
            leftForm->setObjectName(QString::fromUtf8("leftForm"));
        leftForm->resize(100, 609);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leftForm->sizePolicy().hasHeightForWidth());
        leftForm->setSizePolicy(sizePolicy);
        leftForm->setMinimumSize(QSize(100, 0));
        leftForm->setMaximumSize(QSize(100, 16777215));
        gridLayoutWidget = new QWidget(leftForm);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 87, 591));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        cameraPushButton = new QPushButton(gridLayoutWidget);
        cameraPushButton->setObjectName(QString::fromUtf8("cameraPushButton"));

        gridLayout->addWidget(cameraPushButton, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);


        retranslateUi(leftForm);

        QMetaObject::connectSlotsByName(leftForm);
    } // setupUi

    void retranslateUi(QWidget *leftForm)
    {
        leftForm->setWindowTitle(QApplication::translate("leftForm", "Form", 0, QApplication::UnicodeUTF8));
        cameraPushButton->setText(QApplication::translate("leftForm", "camera", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class leftForm: public Ui_leftForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFT_FORM_H
