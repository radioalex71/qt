#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pB_start_toggled(bool checked);
    void on_pB_circle_clicked();
    void on_pB_reset_clicked();
    void updateTimeIndicat(double time);

private:
    Ui::MainWindow *ui;
    Stopwatch *stopwatch;
    int roundCount;
};
#endif // MAINWINDOW_H
