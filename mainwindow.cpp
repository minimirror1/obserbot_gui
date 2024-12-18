#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dashboard_tab.h"
#include "motor_tab.h"
#include "sensor_tab.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    QTabWidget* tabWidget = new QTabWidget(this);
    
    tabWidget->addTab(new DashboardTab(), "Dashboard");
    tabWidget->addTab(new MotorTab(), "Motor");
    tabWidget->addTab(new SensorTab(), "Sensor");
    
    setCentralWidget(tabWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
