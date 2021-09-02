#include "includes/build_settings.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "includes/globalsettings.h"

#include "includes/railcats_logic_objects.h"
#include "includes/railcats_connector_p50.h"
#include "includes/railcats_service.h"

#ifdef RC_PLATFORM_WIN32
#include <sstream>
#endif


extern RailCats_Locomotive MyLoco;
extern RailCats_Connector_p50 dccConnector;
extern RailCats_Service RailCatsService;

extern RailCats_LocoCollection MyLocoCollection;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //std::cout<<"sart"<<std::endl;
    //MyLoco=MyLocoCollection.GetLoco(3);
    //std::cout<<"sart2"<<std::endl;

    MyLoco.SetAddress(0);           // logical address
    MyLoco.SetDirection(1);         // forward
    MyLoco.SetName("0");    // name

    std::cout<<MyLoco.GetAddress()<<std::endl;
    std::cout<<MyLoco.GetDirection()<<std::endl;
    std::cout<<MyLoco.GetName()<<std::endl;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_knob1_sliderMoved(int position)
{

    std::stringstream MYSS;
    std::string OutMessage;

    MYSS<<position;
    MYSS>>OutMessage;

    OutMessage.append(" position");

    MyLoco.SetFn(1,1);

    if(position>0){
        MyLoco.SetDirection(1);
        MyLoco.SetSpeed(position);
    }else{
        MyLoco.SetDirection(0);
        MyLoco.SetSpeed(-position);
    }


    dccConnector.LocoExecute(&MyLoco);
    MyLocoCollection.SetLoco(MyLoco);

    RailCatsService.ThrowLog(0,OutMessage);


}



void MainWindow::on_pushButton_released()
{

        dccConnector.GoConnect();

}

void MainWindow::on_pushButton_2_clicked()
{
    dccConnector.GoDisconnect();
}

void MainWindow::on_pushButton_3_clicked()
{


    std::cout<<"Address="<<MyLoco.GetAddress()<<std::endl;


//    RailCats_Locomotive MyLoco;
    if(MyLoco.GetFn(0)==0){
        MyLoco.SetFn(0,1);

    }else{
        MyLoco.SetFn(0,0);
    };

    dccConnector.LocoExecute(&MyLoco);
    MyLocoCollection.SetLoco(MyLoco);
}

void MainWindow::on_pushButton_4_clicked()
{
    if(MyLoco.GetFn(2)==0){
        MyLoco.SetFn(2,1);
    }else{
        MyLoco.SetFn(2,0);
    }
    dccConnector.LocoExecute(&MyLoco);
    MyLocoCollection.SetLoco(MyLoco);

}

void MainWindow::on_pushButton_5_clicked()
{

    if(MyLoco.GetFn(1)==0){
        MyLoco.SetFn(1,1);
    }else{
        MyLoco.SetFn(1,0);
    }
    dccConnector.LocoExecute(&MyLoco);
    MyLocoCollection.SetLoco(MyLoco);

}

void MainWindow::on_pushButton_6_clicked()
{
    if(MyLoco.GetFn(3)==0){
        MyLoco.SetFn(3,1);
    }else{
        MyLoco.SetFn(3,0);
    }
    dccConnector.LocoExecute(&MyLoco);
    MyLocoCollection.SetLoco(MyLoco);

}

void MainWindow::on_pushButton_7_clicked()
{
    if(MyLoco.GetFn(4)==0){
        MyLoco.SetFn(4,1);
    }else{
        MyLoco.SetFn(4,0);
    }
    dccConnector.LocoExecute(&MyLoco);
    MyLocoCollection.SetLoco(MyLoco);

}

void MainWindow::on_pushButton_8_clicked()
{
    if(MyLoco.GetFn(5)==0){
        MyLoco.SetFn(5,1);
    }else{
        MyLoco.SetFn(5,0);
    }
    dccConnector.LocoExecute(&MyLoco);
    MyLocoCollection.SetLoco(MyLoco);

}

void MainWindow::on_pushButton_9_clicked()
{
    if(MyLoco.GetFn(6)==0){
        MyLoco.SetFn(6,1);
    }else{
        MyLoco.SetFn(6,0);
    }
    dccConnector.LocoExecute(&MyLoco);
    MyLocoCollection.SetLoco(MyLoco);

}

void MainWindow::on_pushButton_10_clicked()
{
    if(MyLoco.GetFn(7)==0){
        MyLoco.SetFn(7,1);
    }else{
        MyLoco.SetFn(7,0);
    }
    dccConnector.LocoExecute(&MyLoco);
    MyLocoCollection.SetLoco(MyLoco);

}

void MainWindow::on_pushButton_11_clicked()
{
    if(MyLoco.GetFn(8)==0){
        MyLoco.SetFn(8,1);
    }else{
        MyLoco.SetFn(8,0);
    }
    dccConnector.LocoExecute(&MyLoco);
    MyLocoCollection.SetLoco(MyLoco);

}

void MainWindow::on_pushButton_14_clicked()
{
    dccConnector.EmergencyStop();
}

void MainWindow::on_pushButton_12_clicked()
{

    QLabel * LocoLabel = this->findChild<QLabel*>("LocoLabel");
    QLCDNumber * LcdNumber = this->findChild<QLCDNumber*>("lcdNumber");
    QPushButton * F1 = this->findChild<QPushButton*>("pushButton_5");
    QPushButton * F2 = this->findChild<QPushButton*>("pushButton_4");
    QPushButton * F3 = this->findChild<QPushButton*>("pushButton_6");
    QPushButton * F4 = this->findChild<QPushButton*>("pushButton_7");
    QPushButton * F5 = this->findChild<QPushButton*>("pushButton_8");
    QPushButton * F6 = this->findChild<QPushButton*>("pushButton_9");
    QPushButton * F7 = this->findChild<QPushButton*>("pushButton_10");
    QPushButton * F8 = this->findChild<QPushButton*>("pushButton_11");
    QPushButton * FL = this->findChild<QPushButton*>("pushButton_3");

    QDial * Knob = this->findChild<QDial*>("knob1");

    if(MyLocoCollection.GetNext(&MyLoco)){

        LocoLabel->setText(QString::fromStdString(MyLoco.GetName()));
        LcdNumber->display(MyLoco.GetAddress());
        F1->setChecked(MyLoco.GetFn(1));
        F2->setChecked(MyLoco.GetFn(2));
        F3->setChecked(MyLoco.GetFn(3));
        F4->setChecked(MyLoco.GetFn(4));
        F5->setChecked(MyLoco.GetFn(5));
        F6->setChecked(MyLoco.GetFn(6));
        F7->setChecked(MyLoco.GetFn(7));
        F8->setChecked(MyLoco.GetFn(8));
        FL->setChecked(MyLoco.GetFn(0));

        if(MyLoco.GetDirection()==1){
            Knob->setValue(MyLoco.GetSpeed());
        }else{
            Knob->setValue(-MyLoco.GetSpeed());
        }
    }

}

void MainWindow::on_pushButton_13_clicked()
{



    QLabel * LocoLabel = this->findChild<QLabel*>("LocoLabel");
    QLCDNumber * LcdNumber = this->findChild<QLCDNumber*>("lcdNumber");
    QPushButton * F1 = this->findChild<QPushButton*>("pushButton_5");
    QPushButton * F2 = this->findChild<QPushButton*>("pushButton_4");
    QPushButton * F3 = this->findChild<QPushButton*>("pushButton_6");
    QPushButton * F4 = this->findChild<QPushButton*>("pushButton_7");
    QPushButton * F5 = this->findChild<QPushButton*>("pushButton_8");
    QPushButton * F6 = this->findChild<QPushButton*>("pushButton_9");
    QPushButton * F7 = this->findChild<QPushButton*>("pushButton_10");
    QPushButton * F8 = this->findChild<QPushButton*>("pushButton_11");
    QPushButton * FL = this->findChild<QPushButton*>("pushButton_3");

    QDial * Knob = this->findChild<QDial*>("knob1");


    if(MyLocoCollection.GetPrev(&MyLoco)){

        LocoLabel->setText(QString::fromStdString(MyLoco.GetName()));
        LcdNumber->display(MyLoco.GetAddress());
        F1->setChecked(MyLoco.GetFn(1));
        F2->setChecked(MyLoco.GetFn(2));
        F3->setChecked(MyLoco.GetFn(3));
        F4->setChecked(MyLoco.GetFn(4));
        F5->setChecked(MyLoco.GetFn(5));
        F6->setChecked(MyLoco.GetFn(6));
        F7->setChecked(MyLoco.GetFn(7));
        F8->setChecked(MyLoco.GetFn(8));
        FL->setChecked(MyLoco.GetFn(0));

        if(MyLoco.GetDirection()==1){
            Knob->setValue(MyLoco.GetSpeed());
        }else{
            Knob->setValue(-MyLoco.GetSpeed());
        }
    }


}

void MainWindow::on_pushButton_16_clicked()
{
    if(MyLocoCollection.SaveToFile("")){
        std::cout<<"Save Ok"<<std::endl;
    }else{
        std::cout<<"Save Error"<<std::endl;
    };
}

void MainWindow::on_pushButton_15_clicked()
{
    if(MyLocoCollection.LoadFromFile("")){
        std::cout<<"Load Ok"<<std::endl;
    }else{
        std::cout<<"Load Error"<<std::endl;

    };
}

void MainWindow::on_knob1_rangeChanged(int min, int max)
{

}
