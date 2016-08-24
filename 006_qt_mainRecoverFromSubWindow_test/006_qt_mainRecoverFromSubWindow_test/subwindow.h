#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QDialog>

namespace Ui {
class SubWindow;
}

class SubWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SubWindow(QWidget *parent = 0);
    ~SubWindow();

protected:
    void closeEvent(QCloseEvent *);

signals:
    void close_me();

private slots:
    void close_child();

private:
    Ui::SubWindow *ui;
    bool m_show_child;
};

#endif // SUBWINDOW_H
