#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"activite.h"
#include"eleve.h"
#include<QMessageBox>
#include<QDebug>
#include <QMainWindow>
#include <QDesktopServices>
#include <QtCharts>
#include "smtp.h"
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QPrinterInfo>
#include <QPrintDialog>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include"participation.h"
#include <curl/curl.h>
#include"note.h"

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

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_17_clicked();

    void on_tableView_2_doubleClicked(const QModelIndex &index);

    void on_pushButton_18_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();



    void on_pushButton_14_clicked();

private:
    Ui::MainWindow *ui;
    Activite act;
    Eleve ect;
     Smtp* smtp;
     Participation ptmp;
     Note ntmp;
};

#endif // MAINWINDOW_H
