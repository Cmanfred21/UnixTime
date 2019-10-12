#ifndef UNIXTIME_H
#define UNIXTIME_H

#include <QWidget>
#include <QTime>
#include <QMouseEvent>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class UnixTime; }
QT_END_NAMESPACE

class UnixTime : public QLabel
{
    Q_OBJECT

public:
    UnixTime(QWidget *parent = nullptr);
    ~UnixTime() override;

private:
    void showTime();
    void mousePressEvent(QMouseEvent *ev) override;
    Ui::UnixTime *ui;
};
#endif // UNIXTIME_H
