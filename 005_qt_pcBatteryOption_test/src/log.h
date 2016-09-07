#ifndef LOG_H
#define LOG_H

#include <QDialog>
#include <QDebug>
#include <QAbstractButton>
#include <QMessageBox>

namespace Ui {
class Log;
}

class Log : public QDialog
{
    Q_OBJECT

public:
    explicit Log(QWidget *parent = 0, QString allLog = "");
    ~Log();

protected:
    void closeEvent(QCloseEvent *);

signals:
    void close_me();

private slots:
    void close_child();

private:
    Ui::Log *ui;
    bool m_show_child;
};

#endif // LOG_H
