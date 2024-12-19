#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dashboard/dashboard_tab.h"
#include "motor/motor_tab.h"
#include "sensor_tab.h"
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // 메뉴바 생성
    QMenuBar* menuBar = new QMenuBar(this);
    
    // File 메뉴 추가
    QMenu* fileMenu = menuBar->addMenu("File");
    
    // Setting 메뉴 및 서브메뉴 추가
    QMenu* settingMenu = menuBar->addMenu("Setting");
    adminAction = settingMenu->addAction("Admin");
    adminAction->setCheckable(true);
    connect(adminAction, &QAction::triggered, this, &MainWindow::onAdminActionTriggered);
    
    // 메뉴바 설정
    setMenuBar(menuBar);
    
    // 탭 위젯 생성
    tabWidget = new QTabWidget(this);
    
    tabWidget->addTab(new DashboardTab(), "Dashboard");
    tabWidget->addTab(new MotorTab(), "Motor");
    tabWidget->addTab(new SensorTab(), "Sensor");
    
    // AdminMode 탭 생성
    adminTab = new QWidget();
    
    setCentralWidget(tabWidget);
}

void MainWindow::onAdminActionTriggered()
{
    if (!isAdminMode) {
        // 비밀번호 입력 다이얼로그 생성
        bool ok;
        QString password = QInputDialog::getText(this, "Admin Mode",
                                               "비밀번호를 입력하세요:",
                                               QLineEdit::Password,
                                               "", &ok);
        
        if (ok && password == adminPassword) {
            // 비밀번호가 맞으면 Admin 모드 활성화
            toggleAdminMode(true);
        } else {
            // 비밀번호가 틀리면 체크 상태 해제
            adminAction->setChecked(false);
            if (ok) {  // 취소가 아닌 경우에만 메시지 표시
                QMessageBox::warning(this, "오류", "비밀번호가 올바르지 않습니다.");
            }
        }
    } else {
        // Admin 모드 비활성화
        toggleAdminMode(false);
    }
}

void MainWindow::toggleAdminMode(bool checked)
{
    if (checked && !isAdminMode) {
        // Admin 모드 활성화
        tabWidget->addTab(adminTab, "AdminMode");
        isAdminMode = true;
        adminAction->setChecked(true);
    } else if (!checked && isAdminMode) {
        // Admin 모드 비활성화
        int adminTabIndex = tabWidget->indexOf(adminTab);
        if (adminTabIndex != -1) {
            tabWidget->removeTab(adminTabIndex);
        }
        isAdminMode = false;
        adminAction->setChecked(false);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
