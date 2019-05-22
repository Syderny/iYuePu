#include "mytextedit.h"
#include <QTextEdit>
#include <QDebug>
#include <QMediaPlayer>
#include <QMediaPlaylist>

MyTextEdit::MyTextEdit(QWidget *parent) : QTextEdit(parent)
{

}

void MyTextEdit::printScale(QPoint point)
{
//    qDebug() << point;
    QString scale;
    if(point.y() > 73) {
        int num = point.x() / 25.4;
        scale = QString('A'+(num%7)) + QString('0'+(num+5)/7);
        this->setText(this->toPlainText() +
                      scale + " ");
    }else {
        int num = (point.x()-11.2) / 25.5;
        if(num*25.5 + 14.7 <= point.x() && num*25.5 + 32.2 >= point.x()){
            if((num+6)%7 != 0 && (num+3)%7 != 0){
                scale = QString('A'+(num%7)) +
                        QString('0'+(num+5)/7) + "#";
                this->setText(this->toPlainText() +
                              scale + " ");
            }
        }
    }

    if(scale.size()){
        emit sendScale(scale);
    }
}
