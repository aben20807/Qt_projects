#include "battery.h"

Battery::Battery(QObject *parent) : QObject(parent)
{

}

int Battery::getBatteryLevel()
{
    QProcess * cmdProcess = new QProcess;
    cmdProcess->start("WMIC PATH Win32_Battery Get EstimatedChargeRemaining");
    cmdProcess->waitForFinished(-1); // will wait forever until finished

    QString out = cmdProcess->readAllStandardOutput();
    QString err = cmdProcess->readAllStandardError();
//    for(int i = 0; i < out.length(); i++){//test the string of output
//        qDebug() << i << out[i] << endl;
//    }
//    qDebug() << out[29] << out[30] << endl;
    if(err != ""){
        qDebug() << "err:" << err << endl;
    }
    int batteryLevel;
    if(out[31] == '0'){
        batteryLevel = 100;
    }
    else {
        batteryLevel = (out[29].unicode()-48)*10 + (out[30].unicode()-48);
//        qDebug() << batteryLevel << endl;
    }
    /*TODO if batteryLevel < 10*/
    return batteryLevel;
}

QString Battery::getBatteryStatus()
{
    QProcess * cmdProcess = new QProcess;
    cmdProcess->start("WMIC Path Win32_Battery Get BatteryStatus");
    cmdProcess->waitForFinished(-1); // will wait forever until finished

    QString out = cmdProcess->readAllStandardOutput();
    QString err = cmdProcess->readAllStandardError();
//    for(int i = 0; i < out.length(); i++){//test the string of output
//        qDebug() << i << out[i] << endl;
//    }
//    qDebug() << out[18] << endl;
    if(err != ""){
        qDebug() << "err:" <<err << endl;
    }
    switch (out[18].unicode()-48) {
    case 1:
        return "Battery using";
    case 2:
        return "AC charging";
    default:
        return "Error!!";
    }
}
