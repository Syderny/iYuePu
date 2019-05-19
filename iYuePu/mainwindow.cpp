#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "keylabel.h"
#include "mytextedit.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QTimer>
#include <QFileDialog>
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    {qApp->setStyleSheet("*{"
                            "border: 0px;"
                            "background: transparent;"
                        "}"

                        "QToolBar{"
                            "background-color: #e5e5e5;"
                        "}"

                        "QToolBar QToolButton{"
                            "color: #151515;"
                            "margin-top: 8px;"
                            "margin-bottom: 8px;"
                            "margin-left: 10px;"
                            "margin-right: 10px;"
                            "font-family: 微软雅黑;"
                            "font-weight: bold;"
                            "font-size: 25px;"
                        "}"

                        "QTextEdit{"
                            "color: #151515;"
                            "font-family: 微软雅黑;"
                            "font-weight: bold;"
                            "font-size: 35px;"
                        "}"

                        "QSpinBox#beat{"
                            "color: white;"
                            "font-family: 微软雅黑;"
                            "font-weight: bold;"
                            "font-size: 32px;"
                        "}"

                        "QComboBox#demo{"
                            "color: white;"
                            "font-family: 微软雅黑;"
                            "font-weight: bold;"
                            "font-size: 28px;"
                        "}"

                        "QWidget#centralWidget{"
                            "border-image: url(:/bg.png);"
                        "}"
                         "QScrollBar:vertical {"
                         "width: 8px;"
                         "background: tranparent;"
                    " }"
                     "QScrollBar:horizontal {"
                      "   height: 8px;"
                   "      background: tranparent;"
                    " }"
                   "  QScrollBar::handle:vertical {"
                 "        background: #626262;"
                  "       min-height: 30px;"
                  "   }"
                   "  QScrollBar::handle:horizontal {"
                    "     background: #626262;"
                      "   min-width: 30px;"
                    " }"
                  "   QScrollBar::handle:vertical:hover,"
                   "  QScrollBar::handle:horizontal:hover {"
                    "     background: #535353;"
                 "    }"
                    " QScrollBar::sub-line:vertical, QScrollBar::add-line:vertical,"
                     "QScrollBar::sub-line:horizontal, QScrollBar::add-line:horizontal {"
                      "   width: 0;"
                       "  height: 0;"
                   "  }"
                     /*make sure the background is solid style.*/
                    " QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical,"
                    " QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {"
                    "     background: none;"
                    " }"

//                        "QPushButton#play{"
//                            "border-image: url(:/play.png);"
//                        "}"
                          "QSpinBox::up-button{"
                            "border-image: url(:/upButton.png);"
                            "height: 12px;"
                            "width: 25px;"
                          "}"

                          "QSpinBox::down-button{"
                            "border-image: url(:/downButton.png);"
                            "height: 12px;"
                            "width: 25px;"
                          "}"

                          "QComboBox::drop-down{"
                             "background: transparent;"
                          "}"
                         "QComboBox QAbstractItemView { "
                          "color: white;"
                          "background-color: #151515;}"
                        );
    }

    //设置上下整体布局
    ui->centralWidget->setLayout(ui->ctrLayout);
    ui->ctrLayout->setStretch(0, 2);
    ui->ctrLayout->setStretch(1, 8);
    ui->ctrLayout->setStretch(2, 2);
    ui->ctrLayout->setStretch(3, 3);
    ui->ctrLayout->setStretch(4, 4);



    //文本框填充满块
    ui->txtWidget->setLayout(ui->txtLayout);
    ui->txtLayout->setStretch(0, 1);
    ui->txtLayout->setStretch(1, 6);
    ui->txtLayout->setStretch(2, 1);
    ui->innerWidget->setLayout(ui->innerLayout);
    textEdit = new MyTextEdit;
    ui->innerLayout->addWidget(textEdit);



    //选中文本的颜色
    QPalette pal = textEdit->palette();
    QColor color;
    color.setNamedColor("#ffffff");
    pal.setColor(QPalette::HighlightedText, color);
    color.setNamedColor("#787878");
    pal.setColor(QPalette::Highlight, color);
    textEdit->setPalette(pal);

    pal = ui->beat->palette();
    color.setNamedColor("#151515");
    pal.setColor(QPalette::Highlight, color);
    ui->beat->setPalette(pal);

    pal = ui->demo->palette();
    color.setNamedColor("#151515");
    pal.setColor(QPalette::Highlight, color);
    ui->demo->setPalette(pal);


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
                     file.close();
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
                     file.close();
                 }
            }
    );
    connect(neww, &QAction::triggered, [=]()mutable{
        textEdit->clear();
    });

    QWidget *spacer = new QWidget;
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    toolbar->addWidget(spacer);

    QAction *half = new QAction("CHR");
    QAction *halfDelay = new QAction("DOT");
    QAction *delay = new QAction("EXT      ");

    toolbar->addAction(half);
    toolbar->addAction(halfDelay);
    toolbar->addAction(delay);

    connect(half, &QAction::triggered, [=]()mutable{
        textEdit->setText(textEdit->toPlainText() + "_");
    });
    connect(halfDelay, &QAction::triggered, [=]()mutable{
        textEdit->setText(textEdit->toPlainText().left(textEdit->toPlainText().size()-1) + "· ");
    });
    connect(delay, &QAction::triggered, [=]()mutable{
        textEdit->setText(textEdit->toPlainText() + " - ");
    });


    //下方按扭区
    ui->btnWidget->setLayout(ui->btnHLayout);
    ui->btnHLayout->setStretch(0, 9);
    ui->btnHLayout->setStretch(1, 6);
    ui->btnHLayout->setStretch(2, 9);
    ui->btnHLayout->setStretch(3, 3);
    ui->btnHLayout->setStretch(4, 8);
    ui->btnHLayout->setStretch(5, 8);
    ui->btnHLayout->setStretch(6, 8);



    //播放按钮
//    qDebug() << ui->play->width();
    ui->play->setIcon(QIcon(":/play.png"));
    ui->play->setIconSize(QSize(56, 63));



    //节拍盒子
    ui->beat->setAlignment(Qt::AlignCenter);



    //键盘
    ui->kbWidget->setLayout(ui->kbHLayout);
    ui->kbHLayout->setStretch(0, 1);
    ui->kbHLayout->setStretch(1, 5);
    ui->kbHLayout->setStretch(2, 1);
 
    ui->scrollAreaWidgetContents->setLayout(ui->keyHLayout);

    ui->scrollAreaWidgetContents->setMaximumSize(120 * 11, 120);

    KeyLabel *picture = new KeyLabel;
    ui->keyHLayout->addWidget(picture);

    QPixmap keyboard;
    keyboard.load(":/keyboard.png");
    picture->setScaledContents(true);
    picture->setPixmap(keyboard);

    connect(picture, &KeyLabel::sendPosition, textEdit,
            &MyTextEdit::printScale);

    connect(textEdit, &MyTextEdit::sendScale, [=](QString scale)mutable{
        QMediaPlayer  *music = new QMediaPlayer(this);
        QMediaPlaylist *playlist = new QMediaPlaylist(this);

        QString runPath = QCoreApplication::applicationDirPath();

        playlist->addMedia(QUrl::fromLocalFile(runPath + "/Piano/" +
                                               scale + ".mp3"));

        music->setPlaylist(playlist);
        music->play();
    });



    //文本
    QTextStream *stream = new QTextStream();
    QString beat;
    QTimer *timer = new QTimer;

    connect(ui->play, &QPushButton::clicked, [=]()mutable{
        if(!timer->isActive()){
            QString *txt = new QString;
            *txt = textEdit->toPlainText();
            stream->setString(txt);
            timer->start(60000 / (ui->beat->value() * 2));
            i = 0;
            ui->play->setIcon(QIcon(":/pause.png"));
        }else {
            timer->stop();
            ui->play->setIcon(QIcon(":/play.png"));
        }
    });

    connect(timer, &QTimer::timeout, [=]()mutable{
        i++;
        if(i % 2 == 0){
            return;
        }
        *stream >> beat;

        if(stream->status() == QTextStream::ReadPastEnd){
            timer->stop();
            ui->play->setIcon(QIcon(":/play.png"));
        }else if(beat == "-"){

        }else {
            QMediaPlayer  *music = new QMediaPlayer(this);
            QMediaPlaylist *playlist = new QMediaPlaylist(this);

            QString runPath = QCoreApplication::applicationDirPath();

            int half = 0;
            if(beat.indexOf("·") > 0){
                half = 1;
            }else if(beat.indexOf("_") >= 0){
                i--;
            }
            beat.replace("·", "");
            beat.replace("_", "");

            playlist->addMedia(QUrl::fromLocalFile(runPath + "/Piano/" +
                                                   beat + ".mp3"));

            music->setPlaylist(playlist);
            music->play();

            if(half){
                timer->stop();
                QThread::msleep(60000 / (ui->beat->value() * 2));
                timer->start(60000 / (ui->beat->value() * 2));
            }

        }
//        qDebug() << i;
    });



    //demo列表
    ui->demo->addItem("DEMO");
    ui->demo->addItem("BIRTHDAY");
    ui->demo->addItem("LITTLE STARS");

    connect(ui->demo, QOverload<int>::of(&QComboBox::currentIndexChanged),
    [=](){
        QString path;
        if(ui->demo->currentIndex() == 1){
            path = ":/soj.txt";
        }else if(ui->demo->currentIndex() == 2){
            path = ":/ls.txt";
        }
        if(ui->demo->currentIndex() != 0){

            QFile file(path);
//          qDebug() << path;
            if(file.open(QFile::ReadOnly)){
                QTextStream fs(&file);
                textEdit->setText(fs.readAll());
            }
            file.close();
        }
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
