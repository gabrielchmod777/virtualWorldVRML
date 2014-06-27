/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created: Fri Jun 27 09:21:33 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogInUi
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_female;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_ip;
    QLineEdit *lineEdit_port;
    QPushButton *pushButton_male;

    void setupUi(QDialog *LogInUi)
    {
        if (LogInUi->objectName().isEmpty())
            LogInUi->setObjectName(QString::fromUtf8("LogInUi"));
        LogInUi->resize(400, 380);
        buttonBox = new QDialogButtonBox(LogInUi);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 340, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gridLayoutWidget = new QWidget(LogInUi);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 371, 311));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_female = new QPushButton(gridLayoutWidget);
        pushButton_female->setObjectName(QString::fromUtf8("pushButton_female"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../../usr/local/share/l3dclient/icons/male.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_female->setIcon(icon);

        gridLayout->addWidget(pushButton_female, 3, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_name = new QLineEdit(gridLayoutWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        gridLayout->addWidget(lineEdit_name, 0, 1, 1, 1);

        lineEdit_ip = new QLineEdit(gridLayoutWidget);
        lineEdit_ip->setObjectName(QString::fromUtf8("lineEdit_ip"));

        gridLayout->addWidget(lineEdit_ip, 1, 1, 1, 1);

        lineEdit_port = new QLineEdit(gridLayoutWidget);
        lineEdit_port->setObjectName(QString::fromUtf8("lineEdit_port"));

        gridLayout->addWidget(lineEdit_port, 2, 1, 1, 1);

        pushButton_male = new QPushButton(gridLayoutWidget);
        pushButton_male->setObjectName(QString::fromUtf8("pushButton_male"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../../../../usr/local/share/l3dclient/icons/female.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_male->setIcon(icon1);

        gridLayout->addWidget(pushButton_male, 4, 1, 1, 1);

        QWidget::setTabOrder(lineEdit_name, lineEdit_ip);
        QWidget::setTabOrder(lineEdit_ip, lineEdit_port);
        QWidget::setTabOrder(lineEdit_port, pushButton_female);
        QWidget::setTabOrder(pushButton_female, pushButton_male);
        QWidget::setTabOrder(pushButton_male, buttonBox);

        retranslateUi(LogInUi);
        QObject::connect(buttonBox, SIGNAL(accepted()), LogInUi, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LogInUi, SLOT(reject()));

        QMetaObject::connectSlotsByName(LogInUi);
    } // setupUi

    void retranslateUi(QDialog *LogInUi)
    {
        LogInUi->setWindowTitle(QApplication::translate("LogInUi", "Log In", 0, QApplication::UnicodeUTF8));
        pushButton_female->setText(QApplication::translate("LogInUi", "PushButton", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LogInUi", "Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LogInUi", "IP", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("LogInUi", "PORT", 0, QApplication::UnicodeUTF8));
        lineEdit_name->setText(QApplication::translate("LogInUi", "visitor", 0, QApplication::UnicodeUTF8));
        lineEdit_ip->setText(QApplication::translate("LogInUi", "localhost", 0, QApplication::UnicodeUTF8));
        lineEdit_port->setText(QApplication::translate("LogInUi", "8080", 0, QApplication::UnicodeUTF8));
        pushButton_male->setText(QApplication::translate("LogInUi", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LogInUi: public Ui_LogInUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
