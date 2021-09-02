#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QWidget>

namespace Ui {
class logwindow;
}

class logwindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit logwindow(QWidget *parent = 0);
    ~logwindow();
    
private:
    Ui::logwindow *ui;
};

#endif // LOGWINDOW_H
