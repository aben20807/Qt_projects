#ifndef CMDPROCESS_H
#define CMDPROCESS_H

#include <QObject>
#include <QProcess>
#include <QDebug>
#include <QMessageBox>

class CmdProcess : public QObject
{
    Q_OBJECT
public:
    explicit CmdProcess(QObject *parent = 0);
    QString getOutputOfBatteryLevel() const;
    QString getOutputOfBatteryStatus() const;
    void doAction(QString const action, int const level, QWidget *m);

signals:

public slots:

private:
    QProcess *cmdProcess;
};

#endif // CMDPROCESS_H
