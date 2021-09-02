#include "includes/globalsettings.h"
#include <QtGui/QApplication>
#include <QTextEdit>
#include "mainwindow.h"
#include "logwindow.h"
#include "loco_new.h"


#include "tinyxml/tinyxml.h"

// Own includes

//RailCats_Settings RailCats_Settings;
//RailCats_Service RailCats_Service;

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    // make main window
    MainWindow window;

    //prepare main window
    //window.resize(800,800);
    window.setWindowTitle("RailCats Qt");

    // show main window
    window.show();
    

    // make log window
    logwindow lwindow;

    // prepare log window
    lwindow.setWindowTitle("RailCats Log");

    // show log window
    lwindow.show();


    // Retrive pointer to textEdit1 from log window
    QTextEdit * textEdit1 = lwindow.findChild<QTextEdit *>("textEdit1");

    // set textEdit as destination for ThrowLog (see RailCats_service for details)
    RailCatsSettings.logWindow=textEdit1;

  /*  RailCats_Protocols_P50 MyProtocol;

    MyProtocol.InitSerial();

    MyProtocol.XLok(0x2b,0,0x10,0x10);

    sleep(2);

    MyProtocol.CloseSerial();*/

    // Activate dccConnector

    dccConnector.GoConnect();

    loco_new loco_new_window;

    loco_new_window.show();

//    extern RailCats_Locomotive MyLoco;
//    MyLoco.SetAddress(1);           // logical address
//    MyLoco.SetDirection(1);         // forward
//    MyLoco.SetName("Test loco");    // name

    // Lets map locomotive to hardware decoder // for testing purposes only
    //dccConnector.MapLocoToDecoder(&MyLoco);

    return application.exec();
}
