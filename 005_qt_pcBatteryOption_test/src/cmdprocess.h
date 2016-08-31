#ifndef CMDPROCESS_H
#define CMDPROCESS_H

#include <QObject>
#include <QProcess>
#include <QDebug>

class CmdProcess : public QObject
{
    Q_OBJECT
public:
    explicit CmdProcess(QObject *parent = 0);
    QString getOutputOfBatteryLevel();
    QString getOutputOfBatteryStatus();
    void doRemindAction();
    void doShutdownAction();
    void doSleepAction();
    void doHibernateAction();

signals:

public slots:
};

#endif // CMDPROCESS_H
