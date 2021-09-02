#ifndef DECODERPROG_H
#define DECODERPROG_H

#include <QWidget>

namespace Ui {
class DecoderProg;
}

class DecoderProg : public QWidget
{
    Q_OBJECT
    
public:
    explicit DecoderProg(QWidget *parent = 0);
    ~DecoderProg();
    
private:
    Ui::DecoderProg *ui;
};

#endif // DECODERPROG_H
