/********************************************************************************
** Form generated from reading UI file 'camerapositioning_dialog.ui'
**
** Created: Thu Feb 27 20:37:32 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAPOSITIONING_DIALOG_H
#define UI_CAMERAPOSITIONING_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraPositionDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label1;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label2;
    QSlider *x_position;
    QVBoxLayout *verticalLayout_4;
    QLabel *label3;
    QSlider *z_position;

    void setupUi(QDialog *CameraPositionDialog)
    {
        if (CameraPositionDialog->objectName().isEmpty())
            CameraPositionDialog->setObjectName(QString::fromUtf8("CameraPositionDialog"));
        CameraPositionDialog->resize(150, 300);
        CameraPositionDialog->setMinimumSize(QSize(150, 300));
        CameraPositionDialog->setMaximumSize(QSize(150, 300));
        verticalLayoutWidget = new QWidget(CameraPositionDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 141, 301));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label1 = new QLabel(verticalLayoutWidget);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label2 = new QLabel(verticalLayoutWidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label2);

        x_position = new QSlider(verticalLayoutWidget);
        x_position->setObjectName(QString::fromUtf8("x_position"));
        x_position->setMinimum(-300);
        x_position->setMaximum(300);
        x_position->setOrientation(Qt::Vertical);

        verticalLayout_3->addWidget(x_position);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label3 = new QLabel(verticalLayoutWidget);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label3);

        z_position = new QSlider(verticalLayoutWidget);
        z_position->setObjectName(QString::fromUtf8("z_position"));
        z_position->setMinimum(-300);
        z_position->setMaximum(300);
        z_position->setOrientation(Qt::Vertical);

        verticalLayout_4->addWidget(z_position);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(CameraPositionDialog);

        QMetaObject::connectSlotsByName(CameraPositionDialog);
    } // setupUi

    void retranslateUi(QDialog *CameraPositionDialog)
    {
        CameraPositionDialog->setWindowTitle(QApplication::translate("CameraPositionDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label1->setText(QApplication::translate("CameraPositionDialog", "Camera Control", 0, QApplication::UnicodeUTF8));
        label2->setText(QApplication::translate("CameraPositionDialog", "X", 0, QApplication::UnicodeUTF8));
        label3->setText(QApplication::translate("CameraPositionDialog", "Z", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CameraPositionDialog: public Ui_CameraPositionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAPOSITIONING_DIALOG_H
