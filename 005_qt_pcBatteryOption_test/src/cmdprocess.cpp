#include "cmdprocess.h"

CmdProcess::CmdProcess(QObject *parent) : QObject(parent)
{
    cmdProcess = new QProcess;
}

QString CmdProcess::getOutputOfBatteryLevel()
{
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
    return out;
}

QString CmdProcess::getOutputOfBatteryStatus()
{
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
    return out;
}

//void CmdProcess::doRemindAction()
//{

//}

//void CmdProcess::doShutdownAction()
//{

//}

//void CmdProcess::doSleepAction()
//{

//}

//void CmdProcess::doHibernateAction()
//{

//}
