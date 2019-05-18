#ifndef KEYLABEL_H
#define KEYLABEL_H

#include <QWidget>
#include <QLabel>

class KeyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit KeyLabel(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event);

signals:
    void sendPosition(QPoint point);

public slots:
};

#endif // KEYLABEL_H
