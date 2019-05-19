#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QWidget>
#include <QTextEdit>

class MyTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit MyTextEdit(QWidget *parent = nullptr);

signals:
    void sendScale(QString scale);

public slots:
    void printScale(QPoint point);
};

#endif // MYTEXTEDIT_H
