#include "unixtime.h"
#include "ui_unixtime.h"
#include <QTimer>
#include <QDateTime>
#include <QClipboard>

UnixTime::UnixTime(QWidget *parent)
    : QLabel(parent)
    , ui(new Ui::UnixTime)
{

    QPalette    pal;
    ui->setupUi(this);
//    setStyleSheet("QLabel { background-color : black; color : white; }");

    pal.setColor(QPalette::Background, Qt::black);
    pal.setColor(QPalette::WindowText, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
    resize(115, 30);

    QFont fon = font();
    fon.setPointSize(15);
    fon.setBold(true);
    setFont(fon);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &UnixTime::showTime);
    timer->start(10);

    showTime();
}

UnixTime::~UnixTime()
{
    delete ui;
}


void    UnixTime::showTime()
{
    qint64 res = QDateTime::currentSecsSinceEpoch();
    QString text = "  " + QString::number(res);
    setText(text);
}

void    UnixTime::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::RightButton)
    {
        QClipboard *clip = QApplication::clipboard();
        clip->setText(text());
    }
}
