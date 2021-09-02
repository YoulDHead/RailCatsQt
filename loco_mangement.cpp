#include "loco_mangement.h"
#include "ui_loco_mangement.h"

loco_mangement::loco_mangement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loco_mangement)
{
    ui->setupUi(this);
}

loco_mangement::~loco_mangement()
{
    delete ui;
}
