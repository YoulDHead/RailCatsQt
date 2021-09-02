#ifndef LOCO_MANGEMENT_H
#define LOCO_MANGEMENT_H

#include <QWidget>

namespace Ui {
class loco_mangement;
}

class loco_mangement : public QWidget
{
    Q_OBJECT
    
public:
    explicit loco_mangement(QWidget *parent = 0);
    ~loco_mangement();
    
private:
    Ui::loco_mangement *ui;
};

#endif // LOCO_MANGEMENT_H
