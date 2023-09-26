#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stpWtch = new Stopwatch(this);

    ui->pb_startStop->setCheckable(true);
    ui->te_timeLog->setReadOnly(true);
    ui->pb_circle->setEnabled(false);

    circleCntr = 0;

    connect(stpWtch, &Stopwatch::sgnl_startTimer, this, &MainWindow::slot_timerDisplay);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_startStop_clicked(bool checked)
{
    if(checked){
        ui->pb_startStop->setText("Стоп");
        ui->pb_circle->setEnabled(true);
        stpWtch->start();
    }
    else{
        ui->pb_startStop->setText("Старт");
        ui->pb_circle->setEnabled(false);
        stpWtch->stop();
    }
}


void MainWindow::on_pb_circle_clicked()
{
    circleCntr++;

    ui->te_timeLog->append("Круг " + QString::number(circleCntr) + ", время " + stpWtch->calcTime());
}


void MainWindow::on_pb_clean_clicked()
{
    this->on_pb_startStop_clicked(false);
    ui->pb_startStop->setChecked(false);

    circleCntr = 0;

    stpWtch->reset();

    ui->te_timeLog->clear();
    ui->l_min->setText("0");
    ui->l_sec->setText("0");
    ui->l_ms->setText("0");
}

void MainWindow::slot_timerDisplay(QString min, QString sec, QString ms)
{
    ui->l_min->setText(min);
    ui->l_sec->setText(sec);
    ui->l_ms->setText(ms);
}

