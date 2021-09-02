#ifndef LOCO_NEW_H
#define LOCO_NEW_H

#include <QWidget>

namespace Ui {
class loco_new;
}

class loco_new : public QWidget
{
    Q_OBJECT
    
public:
    explicit loco_new(QWidget *parent = 0);
    ~loco_new();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::loco_new *ui;
};

#endif // LOCO_NEW_H
