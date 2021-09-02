/********************************************************************************
** Form generated from reading UI file 'logwindow.ui'
**
** Created: Wed 20. Feb 12:05:53 2013
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWINDOW_H
#define UI_LOGWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_logwindow
{
public:
    QTextEdit *textEdit1;

    void setupUi(QWidget *logwindow)
    {
        if (logwindow->objectName().isEmpty())
            logwindow->setObjectName(QString::fromUtf8("logwindow"));
        logwindow->resize(675, 300);
        textEdit1 = new QTextEdit(logwindow);
        textEdit1->setObjectName(QString::fromUtf8("textEdit1"));
        textEdit1->setGeometry(QRect(10, 10, 651, 281));

        retranslateUi(logwindow);

        QMetaObject::connectSlotsByName(logwindow);
    } // setupUi

    void retranslateUi(QWidget *logwindow)
    {
        logwindow->setWindowTitle(QApplication::translate("logwindow", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class logwindow: public Ui_logwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWINDOW_H
