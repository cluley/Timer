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
    void on_pb_startStop_clicked(bool checked);

    void on_pb_circle_clicked();

    void on_pb_clean_clicked();

    void slot_timerDisplay(QString min, QString sec, QString ms);
private:
    Ui::MainWindow *ui;
    Stopwatch* stpWtch;
    int circleCntr;
};
#endif // MAINWINDOW_H
