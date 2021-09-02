#include "decoderprog.h"
#include "ui_decoderprog.h"

DecoderProg::DecoderProg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DecoderProg)
{
    ui->setupUi(this);
}

DecoderProg::~DecoderProg()
{
    delete ui;
}
