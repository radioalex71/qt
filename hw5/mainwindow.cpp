#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),roundCount(0)
{
    ui->setupUi(this);

    ui->lab_time->setText("Время");
    ui->lab_circle->setText("Вывод результатов");
    ui->pB_start->setText("СТАРТ");
    ui->pB_start->setCheckable(true);
    ui->pB_circle->setText("КРУГ");
    ui->pB_reset->setText("СБРОС");

    stopwatch = new Stopwatch(this);
    connect(stopwatch,&Stopwatch::timeChanged,this,&MainWindow::updateTimeIndicat);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pB_start_toggled(bool checked)
{
    if(checked)
    {
        ui->pB_start->setText("СТОП");
        ui->pB_circle->setEnabled(true);
        stopwatch->start();
    }
    else
    {
        ui->pB_start->setText("СТАРТ");
        ui->pB_circle->setEnabled(false);
        double stoppedTime = stopwatch->stop();
        ui->tB_indicat->append(QString("Cтоп: %1 с").arg(stoppedTime,0,'f',1));
    }
}

void MainWindow::on_pB_circle_clicked()
{
roundCount ++;
double roundTime = stopwatch->elapsedTime();
stopwatch->lastTime = roundTime + stopwatch->lastTime;
ui->tB_indicat->append(QString("Круг № %1, время: %2 с").arg(roundCount).arg(roundTime));
}

void MainWindow::on_pB_reset_clicked()
{
stopwatch->reset();
ui->le_time->setText("0.0");
ui->tB_indicat->clear();
roundCount = 0;
}

void MainWindow::updateTimeIndicat(double time)
{
ui->le_time->setText(QString::number(time,'f',1));
}

