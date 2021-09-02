//#include "includes/globalsettings.h"
#include "loco_new.h"
#include "ui_loco_new.h"
#include "includes/railcats_logic_objects.h"
#include "includes/railcats_connector_p50.h"

loco_new::loco_new(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loco_new)
{
    ui->setupUi(this);
}

loco_new::~loco_new()
{
    delete ui;
}

void loco_new::on_pushButton_clicked()
{

    RailCats_Locomotive MyTempLoco;
    extern RailCats_LocoCollection MyLocoCollection;
    extern RailCats_Service RailCatsService;
    extern RailCats_Connector_p50 dccConnector;

    MyTempLoco.SetName("aaaaa");

    std::cout<<"1"<<std::endl;

    // SetName
    QLineEdit * TempLineEdit1 = this->findChild<QLineEdit *> ("lineEdit");

    MyTempLoco.SetName(TempLineEdit1->text().toStdString());

    // SetLogicalAddress
    QLineEdit * TempLineEdit2 = this->findChild<QLineEdit *>("lineEdit_2");
    MyTempLoco.SetAddress(TempLineEdit2->text().toInt());

    // Add loco to collection
    if(MyLocoCollection.AddLoco(MyTempLoco)){
        RailCatsService.ThrowLog(3,"LocoAdded Ok");
    }else{
        RailCatsService.ThrowLog(3,"LocoAdded Error");
        return;
    }

    RailCats_Connector_p50_Loco_Decoder_DCC MyTempDecoder;

    // Set HW Address
    QSpinBox * TempSpinBox1 = this->findChild<QSpinBox*>("spinBox");
    int HWAddress=TempSpinBox1->text().toInt();

    MyTempDecoder.SetHWAddress(HWAddress);

    // Set decoder Logical address of loco
    MyTempDecoder.SetLAddress(MyTempLoco.GetAddress());


    // Set decoder Steps
    QSpinBox * TempSpinBox2 = this->findChild<QSpinBox*>("spinBox_2");
    MyTempDecoder.SetSteps(TempSpinBox2->text().toInt());

    // map loco and decoder
    dccConnector.MapLocoToDecoder(&MyTempLoco,&MyTempDecoder);

}
