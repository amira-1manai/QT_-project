#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"Activite.h"
#include"eleve.h"
#include<QMessageBox>
#include<QDebug>
#include <QMainWindow>
#include <QDesktopServices>
#include <QtCharts>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    Activite act;
    Eleve ect;

};

#endif // MAINWINDOW_H
