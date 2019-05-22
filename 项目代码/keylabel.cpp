#include "keylabel.h"
#include <QDebug>
#include <QMouseEvent>

KeyLabel::KeyLabel(QWidget *parent) : QLabel(parent)
{

}

void KeyLabel::mousePressEvent(QMouseEvent *event)
{
    emit sendPosition(event->pos());
}
