#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QDialog>

namespace Ui {
class Schedule;
}

class Schedule : public QDialog
{
    Q_OBJECT

public:
    explicit Schedule(QWidget *parent = 0);
    ~Schedule();

protected:
    void closeEvent(QCloseEvent *);//

signals:
    void close_me();//

private slots:
    void close_child();//

private:
    Ui::Schedule *ui;
    bool m_show_child;
};

#endif // SCHEDULE_H
