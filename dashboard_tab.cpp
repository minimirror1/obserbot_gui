#include "dashboard_tab.h"
#include <QVBoxLayout>
#include <QGridLayout>

DashboardTab::DashboardTab(QWidget *parent) : QWidget(parent)
{
    QGridLayout* layout = new QGridLayout(this);
    
    // 4개의 위젯을 생성하고 그리드에 배치
    QWidget* widget1 = new QWidget(this);
    QWidget* widget2 = new QWidget(this);
    QWidget* widget3 = new QWidget(this);
    QWidget* widget4 = new QWidget(this);
    
    // 임시로 각 위젯에 스타일 설정 (구분을 위해)
    widget1->setStyleSheet("background-color: #f0f0f0;");
    widget2->setStyleSheet("background-color: #e0e0e0;");
    widget3->setStyleSheet("background-color: #d0d0d0;");
    widget4->setStyleSheet("background-color: #c0c0c0;");
    
    // 그리드에 위젯 배치 (행, 열 순서로 지정)
    layout->addWidget(widget1, 0, 0);  // 좌상단
    layout->addWidget(widget2, 0, 1);  // 우상단
    layout->addWidget(widget3, 1, 0);  // 좌하단
    layout->addWidget(widget4, 1, 1);  // 우하단
} 