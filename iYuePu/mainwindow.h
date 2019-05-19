#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mytextedit.h"
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

namespace Ui {

class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    int i;
    MyTextEdit *textEdit;
};

#endif // MAINWINDOW_H
