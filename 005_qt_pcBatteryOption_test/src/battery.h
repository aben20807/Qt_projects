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
    int getBatteryLevel();
    QString getBatteryStatus();

signals:

public slots:

private:

};

#endif // BATTERY_H
