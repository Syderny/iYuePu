#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



//    //设置整体布局，随窗口大小变化而变化
//    ui->centralWidget->setLayout(ui->ctrLayout);



//    //添加工具栏的文件操作按钮
//    QToolBar *toolbar = ui->mainToolBar;

//    QAction *open = new QAction("打开");
//    QAction *save = new QAction("保存");
//    QAction *neww = new QAction("新建");

//    toolbar->addAction(open);
//    toolbar->addAction(save);
//    toolbar->addAction(neww);



//    //上下布局
//    ui->mjLayout->setStretch(0, 4);
//    ui->mjLayout->setStretch(1, 1);



//    //下方按扭区
//    ui->btnWidget->setLayout(ui->btnHLayout);
//    ui->btnHLayout->setStretch(0, 1);
//    ui->btnHLayout->setStretch(1, 1);
//    ui->btnHLayout->setStretch(2, 1);
//    ui->btnHLayout->setStretch(3, 1);
//    ui->btnHLayout->setStretch(4, 1);



//    //上方文本框键盘布局
//    ui->txtBrdWidget->setLayout(ui->txtBrdHLayout);
//    ui->txtBrdHLayout->setStretch(0, 1);
//    ui->txtBrdHLayout->setStretch(1, 1);



//    //文本框填充满块
//    ui->txtWidget->setLayout(ui->txtLayout);



//    //键盘乐器选项布局
//    ui->brdWidget->setLayout(ui->brdVLayout);
//    ui->brdVLayout->setStretch(0, 3);
//    ui->brdVLayout->setStretch(1, 1);



//    //生成键盘
//    QGridLayout *kbLayout = ui->kbLayout;
//    ui->keyboard->setLayout(kbLayout);

//    for (int i = 0; i <= 8; ++i) {
//        QList<QPushButton*> *row = new QList<QPushButton*>;

//        for (int j = 0; j < 7; ++j) {
//            QPushButton *key = new QPushButton(QString('A'+((j+2)%7)) + QString('0'+i));
//            row->push_back(key);
//            kbLayout->addWidget(key, i, 2*j, 1, 1);

//            QPushButton *keyr = new QPushButton(QString('A'+((j+2)%7))
//                                                + QString('0'+i) + QString('#'));
//            row->push_back(keyr);
//            kbLayout->addWidget(keyr, i, 2*j+1, 1, 1);
//        }

//        keys.push_back(row);
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
