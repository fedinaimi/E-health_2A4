#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include"utilisateur.h"
#include "mainwindow.h"
#include<QApplication>
#include<QtCharts/QChartView>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QHorizontalStackedBarSeries>
#include<QtCharts/QLineSeries>
#include<QtCharts/QCategoryAxis>
#include<QtCharts/QPieSeries>
#include<QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

mainwindow1::mainwindow1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainwindow1)
{
    ui->setupUi(this);
    QBarSet *set0 = new QBarSet("Nombre");
     utilisateur u;
       *set0 << u.calculertype("medecin") << u.calculertype("secretaire") ;


       QBarSeries *series = new QBarSeries();
          series->append(set0);

          QChart *chart = new QChart();
              chart->addSeries(series);
              chart->setTitle("Statistique des nombres des animaux par rapport à leurs types");
              chart->setAnimationOptions(QChart::SeriesAnimations);
              QStringList categories;
                 categories << "Chien" << "Cheval" << "Chat"  << "volaille"<<"Bovin";
                 QBarCategoryAxis *axisX = new QBarCategoryAxis();
                 axisX->append(categories);
                 chart->addAxis(axisX, Qt::AlignBottom);
                 series->attachAxis(axisX);

                 QValueAxis *axisY = new QValueAxis();
                 axisY->setRange(0,10);
                 chart->addAxis(axisY, Qt::AlignLeft);
                 series->attachAxis(axisY);
                 chart->legend()->setVisible(true);
                    chart->legend()->setAlignment(Qt::AlignBottom);
                    QChartView *chartView = new QChartView(chart);
                        chartView->setRenderHint(QPainter::Antialiasing);
                        setCentralWidget(chartView);

}

mainwindow1::~mainwindow1()
{
    delete ui;
}

