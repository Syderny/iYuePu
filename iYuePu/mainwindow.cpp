#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    //设置上下整体布局
    ui->centralWidget->setLayout(ui->ctrLayout);
    ui->ctrLayout->setStretch(0, 1);
    ui->ctrLayout->setStretch(1, 4);
    ui->ctrLayout->setStretch(2, 1);
    ui->ctrLayout->setStretch(3, 2);
    ui->ctrLayout->setStretch(4, 2);



    //添加工具栏的文件操作按钮
    QToolBar *toolbar = ui->mainToolBar;

    QAction *open = new QAction("OPEN");
    QAction *save = new QAction("SAVE");
    QAction *neww = new QAction("NEW");

    toolbar->addAction(open);
    toolbar->addAction(save);
    toolbar->addAction(neww);



    //文本框填充满块
    ui->txtWidget->setLayout(ui->txtLayout);
    ui->txtLayout->setStretch(0, 1);
    ui->txtLayout->setStretch(1, 6);
    ui->txtLayout->setStretch(2, 1);



    //下方按扭区
    ui->btnWidget->setLayout(ui->btnHLayout);



    //键盘
    ui->kbWidget->setLayout(ui->kbHLayout);
    ui->kbHLayout->setStretch(0, 1);
    ui->kbHLayout->setStretch(1, 6);
    ui->kbHLayout->setStretch(2, 1);

    ui->scrollAreaWidgetContents->setLayout(ui->keyHLayout);
//    QVBoxLayout *keyLayout = ui->keyLayout;

}

MainWindow::~MainWindow()
{
    delete ui;
}
