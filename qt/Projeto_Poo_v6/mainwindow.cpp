#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "file_log.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QtCore/QDateTime>
#include <QFileDialog>




QString local = "C:/dados/qt/Projeto_Poo_v6/arquivos/";
QString nome2 = local+"durstprtd2.log";
QString nome = local+"durstprtd.log";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btn_filtrar_clicked()
{
    QString strerror, machine;


    const QString fileName = QFileDialog::getOpenFileName(this);
    //if (!fileName.isEmpty())



    file_log log1 = file_log(fileName);
    log1.filtro(".01GTT");  //temperatura
    log1.filtro(".01QPT");  //peças impressas

    log1.geterror(strerror);
    ui->txtbrerror->setPlainText(strerror);

    //ui->label_2->setText(log1.printname());
    ui->label_2->setText(log1.getmachine());

    file_log log2 = file_log(nome2);
    log2.filtro(".01GTT");



}
