#include "form_2.h"
#include "ui_form_2.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCore/QDateTime>
#include <QtCharts/QDateTimeAxis>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QDebug>
#include <QtCharts/QValueAxis>
#include <QScatterSeries>
#include <QCategoryAxis>


QT_CHARTS_USE_NAMESPACE

form_2::form_2(QWidget *parent, QVector<double> *vec_temp, QVector<QTime> *vec_time, QString titlegraph) :
    QDialog(parent),
    ui(new Ui::form_2)
{
    ui->setupUi(this);

    QDateTime xValue;

    QScatterSeries *series = new QScatterSeries();


    for (int i = 0; i < vec_temp->size(); ++i){
        xValue.setTime( vec_time->value(i));
        series->append(xValue.toMSecsSinceEpoch(),vec_temp->value(i));

    }

    series->setPen(QPen(Qt::transparent));
    series->setMarkerSize(1);
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle(titlegraph);
    QDateTimeAxis *axisX = new QDateTimeAxis;
    //QCategoryAxis *axisY = new QCategoryAxis();
    axisX->setFormat("h");
    //axisY->setRange(0, 100);

    chart->setAxisX(axisX,series);
    //chart->setAxisY(axisY,series);


    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalFrame);



}

form_2::~form_2()
{
    delete ui;
}


