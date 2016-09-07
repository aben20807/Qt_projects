#include "cmdprocess.h"

CmdProcess::CmdProcess(QObject *parent) : QObject(parent)
{
    cmdProcess = new QProcess;
}

QString CmdProcess::getOutputOfBatteryLevel() const
{
    cmdProcess->start("WMIC PATH Win32_Battery Get EstimatedChargeRemaining");
    cmdProcess->waitForFinished(-1); // will wait forever until finished
    QString out = cmdProcess->readAllStandardOutput();
    QString err = cmdProcess->readAllStandardError();
    //for(int i = 0; i < out.length(); i++){//test the string of output
    //  qDebug() << i << out[i] << endl;
    //}
    //qDebug() << out[29] << out[30] << endl;
    if(err != ""){
        qDebug() << "err:" << err << endl;
    }
    cmdProcess->start("cls");//clean cmd
    cmdProcess->waitForFinished(-1); // will wait forever until finished
    return out;
}

QString CmdProcess::getOutputOfBatteryStatus() const
{
    cmdProcess->start("WMIC Path Win32_Battery Get BatteryStatus");
    cmdProcess->waitForFinished(-1); // will wait forever until finished
    QString out = cmdProcess->readAllStandardOutput();
    QString err = cmdProcess->readAllStandardError();
    //for(int i = 0; i < out.length(); i++){//test the string of output
    //  qDebug() << i << out[i] << endl;
    //}
    //qDebug() << out[18] << endl;
    if(err != ""){
        qDebug() << "err:" <<err << endl;
    }
    cmdProcess->start("cls");//clean cmd
    cmdProcess->waitForFinished(-1); // will wait forever until finished
    return out;
}

void CmdProcess::doAction(QString const action, int const level, QWidget *m)
{
    if(action == "RemindMorethan"){
        QMessageBox::warning(m, tr("Remind"), (tr("Battery level is more than ")+ QString::number(level)));
    }
    else if(action == "RemindLessthan"){
        QMessageBox::warning(m, tr("Remind"), tr("Battery level is less than ")+ QString::number(level));
    }
    else if(action == "Shutdown"){
        cmdProcess->start("shutdown /s");
        cmdProcess->waitForFinished(-1); // will wait forever until finished
        cmdProcess->start("cls");//clean cmd
        cmdProcess->waitForFinished(-1); // will wait forever until finished
        //QString out = cmdProcess->readAllStandardOutput();
        QString err = cmdProcess->readAllStandardError();
        if(err != ""){
            qDebug() << "err:" <<err << endl;
        }
        //qDebug() << "out:" << out << endl;
    }
    else if(action == "Sleep"){
        cmdProcess->start("powercfg -hibernate off");
        cmdProcess->waitForFinished(-1);
        cmdProcess->start("rundll32.exe powrprof.dll,SetSuspendState Sleep");
        cmdProcess->waitForFinished(-1); // will wait forever until finished
        cmdProcess->start("cls");//clean cmd
        cmdProcess->waitForFinished(-1); // will wait forever until finished
        //QString out = cmdProcess->readAllStandardOutput();
        QString err = cmdProcess->readAllStandardError();
        if(err != ""){
            qDebug() << "err:" <<err << endl;
        }
        //qDebug() << "out:" << out << endl;
    }
    else if(action == "Hibernate"){
        cmdProcess->start("powercfg -hibernate on");
        cmdProcess->waitForFinished(-1);
        cmdProcess->start("shutdown /h");
        cmdProcess->waitForFinished(-1); // will wait forever until finished
        cmdProcess->start("cls");//clean cmd
        cmdProcess->waitForFinished(-1); // will wait forever until finished
        //QString out = cmdProcess->readAllStandardOutput();
        QString err = cmdProcess->readAllStandardError();
        if(err != ""){
            qDebug() << "err:" <<err << endl;
        }
        //qDebug() << "out:" << out << endl;
    }
    return;
}
