/********************************************************************************
** Form generated from reading UI file 'loco_new.ui'
**
** Created: Wed 20. Feb 12:05:53 2013
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCO_NEW_H
#define UI_LOCO_NEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loco_new
{
public:
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label_5;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *loco_new)
    {
        if (loco_new->objectName().isEmpty())
            loco_new->setObjectName(QString::fromUtf8("loco_new"));
        loco_new->resize(556, 300);
        pushButton = new QPushButton(loco_new);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(430, 260, 95, 31));
        groupBox = new QGroupBox(loco_new);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 541, 71));
        groupBox->setFlat(false);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 81, 21));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 30, 191, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(310, 30, 91, 21));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(400, 30, 113, 21));
        groupBox_2 = new QGroupBox(loco_new);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 80, 531, 151));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setGeometry(QRect(420, 110, 95, 31));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 67, 21));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 60, 67, 21));
        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(90, 30, 59, 21));
        spinBox->setMaximum(999);
        spinBox_2 = new QSpinBox(groupBox_2);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(90, 60, 59, 21));
        spinBox_2->setMaximum(999);
        pushButton_3 = new QPushButton(loco_new);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(false);
        pushButton_3->setGeometry(QRect(20, 260, 95, 31));

        retranslateUi(loco_new);

        QMetaObject::connectSlotsByName(loco_new);
    } // setupUi

    void retranslateUi(QWidget *loco_new)
    {
        loco_new->setWindowTitle(QApplication::translate("loco_new", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("loco_new", "Add", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("loco_new", "Loco properties", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("loco_new", "LocoName", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("loco_new", "LocoNumber", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("loco_new", "Decoder properties", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("loco_new", "Read", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("loco_new", "Address", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("loco_new", "Steps", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("loco_new", "Programm", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class loco_new: public Ui_loco_new {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCO_NEW_H
