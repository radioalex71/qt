#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_rBut1_val_clicked();

    void on_rBut2_perc_clicked();

    void on_cB_speedEng_activated(int index);

    void on_pB_start_toggled(bool checked);

    void on_pB_reset_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
