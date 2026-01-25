#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gB_data->setTitle("Выбор вариантов индикации");
    ui->rBut1_val->setText("Градусы");
    ui->rBut2_perc->setText("Проценты");

    ui->gB_engine->setTitle("Управление скоростью вращения двигателя");
    ui->lab_speedEng->setText("Выбор скорости двигателя");
    for(int i = 0; i <=3; ++i)
    {
        ui->cB_speedEng->addItem(QString("x %1").arg(i));
    }

    ui->pB_start->setText("Пуск");
    ui->pB_start->setCheckable(true);

    ui->pB_indicat->setMinimum(0);//для ДЗ
    ui->pB_indicat->setMaximum(100);//для ДЗ
    ui->pB_indicat->setValue(0);//для ДЗ

    ui->pB_reset->setText(QString("СБРОС"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_rBut1_val_clicked()
{
    ui->pB_indicat->setFormat("%v град.");
}


void MainWindow::on_rBut2_perc_clicked()
{
    ui->pB_indicat->setFormat("%p %");
}


void MainWindow::on_cB_speedEng_activated(int index)
{
    ui->cB_speedEng->currentIndex();
}


void MainWindow::on_pB_start_toggled(bool checked)
{
    int index = ui->cB_speedEng->currentIndex();

    if(checked)
    {
      ui->pB_start->setText("СТОП");
      int v = ui->pB_indicat->value();
      int step = 0;
      int val = 0;
      switch (index)
      {
      case 1:
          step = 10;
          val = v + step;
          ui->pB_indicat->setValue(val);
          break;
      case 2:
          step = 20;
          val = v + step;
          ui->pB_indicat->setValue(val);
          break;
      case 3:
          step = 30;
          val = v + step;
          ui->pB_indicat->setValue(val);
          break;
      default:
          ui->pB_indicat->setValue(0);
          break;
      }
      if(val>100)
      {ui->pB_indicat->setValue(0);}
    }
    else
  {
     ui->pB_start->setText("ПУСК");
     int currentVal = ui->pB_indicat->value();
     ui->pB_indicat->setValue(currentVal);

  }

}

void MainWindow::on_pB_reset_clicked()
{
    ui->pB_indicat->setValue(0);
    ui->cB_speedEng->setCurrentIndex(0);
}

