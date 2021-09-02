/********************************************************************************
** Form generated from reading UI file 'loco_mangement.ui'
**
** Created: Wed 20. Feb 12:05:53 2013
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCO_MANGEMENT_H
#define UI_LOCO_MANGEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loco_mangement
{
public:

    void setupUi(QWidget *loco_mangement)
    {
        if (loco_mangement->objectName().isEmpty())
            loco_mangement->setObjectName(QString::fromUtf8("loco_mangement"));
        loco_mangement->resize(653, 426);

        retranslateUi(loco_mangement);

        QMetaObject::connectSlotsByName(loco_mangement);
    } // setupUi

    void retranslateUi(QWidget *loco_mangement)
    {
        loco_mangement->setWindowTitle(QApplication::translate("loco_mangement", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class loco_mangement: public Ui_loco_mangement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCO_MANGEMENT_H
