#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_language_currentTextChanged(const QString &language)
{
    QTranslator *translator =  new  QTranslator(qApp);
    if(language == "繁體中文"){
        qDebug() << "change to 繁體中文" << endl;
//        translator->load(QString("./language/zh_TW"));
    }
    else if(language == "English"){
        qDebug() << "change to English" << endl;
//        translator->load(QString("./language/en_US"));
    }
    else{

    }
    qApp->installTranslator(translator);
}
