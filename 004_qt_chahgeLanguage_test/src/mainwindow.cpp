#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Qt::WindowFlags flags = 0;
    flags |= Qt::WindowMinimizeButtonHint;
    flags |= Qt::WindowCloseButtonHint;
    setWindowFlags(flags);//Maximize ban
    setFixedSize(QWidget::geometry().width(), QWidget::geometry().height());//Prohibition on changing the window size
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_ok_clicked()
{
    QTranslator *translator =  new  QTranslator(qApp);
    if(ui->comboBox->currentText() == "繁體中文"){
        translator->load(QString( "./language/zh_TW" ));
    }
    else if(ui->comboBox->currentText() == "English"){
        translator->load(QString( "./language/en_US" ));
    }
    else if(ui->comboBox->currentText() == "日本語"){
        translator->load(QString( "./language/ja_JP" ));
    }
    else{

    }
    qApp->installTranslator( translator );
    this->initGUI();
}

void  MainWindow::initGUI()
{
    this->setWindowTitle(tr("主視窗"));
    this->ui->btn_ok->setText(tr("確認"));
    this->ui->comboBox->setItemText(0,tr("請選擇語言"));//set the first item
    this->ui->comboBox->setCurrentText(tr("請選擇語言"));//set first item to current text
    this->ui->label_hello->setText(tr("你好"));
}
