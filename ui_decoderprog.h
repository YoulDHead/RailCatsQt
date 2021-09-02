/********************************************************************************
** Form generated from reading UI file 'decoderprog.ui'
**
** Created: Wed 20. Feb 12:05:53 2013
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DECODERPROG_H
#define UI_DECODERPROG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DecoderProg
{
public:

    void setupUi(QWidget *DecoderProg)
    {
        if (DecoderProg->objectName().isEmpty())
            DecoderProg->setObjectName(QString::fromUtf8("DecoderProg"));
        DecoderProg->setWindowModality(Qt::WindowModal);
        DecoderProg->resize(399, 250);

        retranslateUi(DecoderProg);

        QMetaObject::connectSlotsByName(DecoderProg);
    } // setupUi

    void retranslateUi(QWidget *DecoderProg)
    {
        DecoderProg->setWindowTitle(QApplication::translate("DecoderProg", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DecoderProg: public Ui_DecoderProg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DECODERPROG_H
