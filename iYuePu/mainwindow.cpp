#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    //设置整体布局，随窗口大小变化而变化
    ui->centralWidget->setLayout(ui->ctrLayout);



    //添加工具栏的文件操作按钮
    //设置工具栏不可移动
    QToolBar *toolbar = ui->mainToolBar;

    QAction *open = new QAction("打开");
    QAction *save = new QAction("保存");
    QAction *neww = new QAction("新建");

    toolbar->addAction(open);
    toolbar->addAction(save);
    toolbar->addAction(neww);

    toolbar->setFloatable(false);





}

MainWindow::~MainWindow()
{
    delete ui;
}
