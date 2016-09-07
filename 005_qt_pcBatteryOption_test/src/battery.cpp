#include "battery.h"

Battery::Battery(QObject *parent) : QObject(parent)
{
    cmdprocess = new CmdProcess;
}

int Battery::getBatteryLevel() const
{
    QString out = cmdprocess->getOutputOfBatteryLevel();
    int batteryLevel;
    if(out[31] == '0'){//if batteryLevel = 100
        batteryLevel = 100;
    }
    else if(out[30] > '9' || out[30] < '0'){//if batteryLevel < 10
        batteryLevel = (out[29].unicode()-48);
    }
    else {
        batteryLevel = (out[29].unicode()-48)*10 + (out[30].unicode()-48);
        //qDebug() << batteryLevel << endl;
    }
    return batteryLevel;
}

QString Battery::getBatteryStatus() const
{
    QString out = cmdprocess->getOutputOfBatteryStatus();
    switch (out[18].unicode()-48) {
    case 1:
        return "Battery using";
    case 2:
        return "AC charging";
    default:
        return "Error!!";
    }
}
