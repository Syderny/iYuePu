#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "keylabel.h"
#include "mytextedit.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QTimer>
#include <QFileDialog>

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


    //文本框填充满块
    ui->txtWidget->setLayout(ui->txtLayout);
    ui->txtLayout->setStretch(0, 1);
    ui->txtLayout->setStretch(1, 6);
    ui->txtLayout->setStretch(2, 1);
    ui->innerWidget->setLayout(ui->innerLayout);
    MyTextEdit *textEdit = new MyTextEdit;
    ui->innerLayout->addWidget(textEdit);



    //添加工具栏的文件操作按钮
    QToolBar *toolbar = ui->mainToolBar;

    QAction *open = new QAction("OPEN");
    QAction *save = new QAction("SAVE");
    QAction *neww = new QAction("CLEAR");

    toolbar->addAction(open);
    toolbar->addAction(save);
    toolbar->addAction(neww);

    connect(open, &QAction::triggered,
            [=](){
                 QString path = QFileDialog::getOpenFileName(
                             this, "Open sheet music","../",
                             "Sheet music(*.txt)");
                 if(path.size()){
                     QFile file(path);
                     if(file.open(QFile::ReadOnly)){
                         QTextStream fs(&file);
                         textEdit->setText(fs.readAll());
                     }
                 }
            }
    );
    connect(save, &QAction::triggered,
            [=](){
                 QString path = QFileDialog::getSaveFileName(
                             this, "Save sheet music", "../untitled.txt",
                             "Sheet music(*.txt)");
                 if(path.size()){
                     QFile file(path);
                     if(file.open(QFile::WriteOnly)){
                         QTextStream fs(&file);
                         fs << textEdit->toPlainText();
                     }
                 }
            }
    );
    connect(neww, &QAction::triggered, [=]()mutable{
        textEdit->clear();
    });



    //下方按扭区
    ui->btnWidget->setLayout(ui->btnHLayout);

    

    //键盘
    ui->kbWidget->setLayout(ui->kbHLayout);
    ui->kbHLayout->setStretch(0, 1);
    ui->kbHLayout->setStretch(1, 6);
    ui->kbHLayout->setStretch(2, 1);
 
    ui->scrollAreaWidgetContents->setLayout(ui->keyHLayout);
    ui->scrollAreaWidgetContents->setMaximumSize(170 * 11, 170);

    KeyLabel *picture = new KeyLabel;
    ui->keyHLayout->addWidget(picture);

    QPixmap keyboard;
    keyboard.load(":/keyboard.png");
    picture->setScaledContents(true);
    picture->setPixmap(keyboard);

    connect(picture, &KeyLabel::sendPosition, textEdit,
            &MyTextEdit::printScale);



    //文本

    QTextStream *stream = new QTextStream();
    QString beat;
    QTimer *timer = new QTimer;

    connect(ui->play, &QPushButton::clicked, [=]()mutable{
        if(!timer->isActive()){
            QString *txt = new QString;
            *txt = textEdit->toPlainText();
            stream->setString(txt);
            timer->start(60000.0 / (double)ui->beat->value());
        }else {
            timer->stop();
        }
    });
    connect(timer, &QTimer::timeout, [=]()mutable{
        *stream >> beat;

        if(stream->status() == QTextStream::ReadPastEnd){
            timer->stop();
        }else if(beat == "-"){

        }else {
            QMediaPlayer  *music = new QMediaPlayer(this);
            QMediaPlaylist *playlist = new QMediaPlaylist(this);

            QString runPath = QCoreApplication::applicationDirPath();

            playlist->addMedia(QUrl::fromLocalFile(runPath + "/Piano/" +
                                                   beat + ".mp3"));

            music->setPlaylist(playlist);
            music->play();
        }
    });


    //demo列表
    ui->demo->addItem("Demo");
    ui->demo->addItem("Ode an die Freude");
    ui->demo->addItem("Far Away");
}

MainWindow::~MainWindow()
{
    delete ui;
}
