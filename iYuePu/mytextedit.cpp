#include "mytextedit.h"
#include <QTextEdit>
#include <QDebug>

MyTextEdit::MyTextEdit(QWidget *parent) : QTextEdit(parent)
{

}

void MyTextEdit::printScale(QPoint point)
{
//    qDebug() << point;
    if(point.y() > 102) {
        int num = point.x() / 36;
        this->setText(this->toPlainText() +
                      QString('A'+(num%7)) + QString('0'+(num+5)/7) + " ");
    }else {
        int num = (point.x()-16) / 36;
        if(num*36 + 21 <= point.x() && num*36 + 46 >= point.x()){
            if((num+6)%7 != 0 && (num+3)%7 != 0){
                this->setText(this->toPlainText() +
                              QString('A'+(num%7)) +
                              QString('0'+(num+5)/7) + "# ");
            }
        }
    }
}
