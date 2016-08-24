#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "subwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void gotoSubWindow();//這個可自訂，也可以是按按鈕或其它

private slots:
    void close_child();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    bool m_show_child;
};

#endif // MAINWINDOW_H
