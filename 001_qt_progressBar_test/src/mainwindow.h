#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void Timer();
    QTimer *timer;

public slots:
    void MySlot();

private slots:
    void on_pushButton_0_clicked();

    void on_pushButton_100_clicked();

    void on_pushButton_add10_clicked();

    void on_pushButton_sub10_clicked();

    void on_pushButton_autorun_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    bool flag;
};

#endif // MAINWINDOW_H
