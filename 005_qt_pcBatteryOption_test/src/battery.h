#ifndef BATTERY_H
#define BATTERY_H

#include <QObject>
#include <QProcess>
#include <QDebug>
#include "cmdprocess.h"

class Battery : public QObject
{
    Q_OBJECT
public:
    explicit Battery(QObject *parent = 0);
    int getBatteryLevel() const;
    QString getBatteryStatus() const;

signals:

public slots:

private:
    CmdProcess *cmdprocess;
};

#endif // BATTERY_H
