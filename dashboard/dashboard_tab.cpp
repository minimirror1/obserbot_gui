#include "dashboard_tab.h"
#include "camera_widget.h"
#include "scenario_widget.h"
#include "motor_widget.h"
#include "control_widget.h"
#include <QVBoxLayout>
#include <QSplitter>

DashboardTab::DashboardTab(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* main_layout = new QVBoxLayout(this);
    
    // 수직 분할을 위한 메인 스플리터
    QSplitter* v_splitter = new QSplitter(Qt::Vertical, this);
    
    // 상단과 하단의 수평 스플리터
    QSplitter* h_splitter_top = new QSplitter(Qt::Horizontal);
    QSplitter* h_splitter_bottom = new QSplitter(Qt::Horizontal);
    
    // 커스텀 위젯 생성
    camera_widget = new CameraWidget(this);
    scenario_widget = new ScenarioWidget(this);
    motor_widget = new MotorWidget(this);
    control_widget = new ControlWidget(this);
    
    // 상단 스플리터에 위젯 추가
    h_splitter_top->addWidget(camera_widget);
    h_splitter_top->addWidget(scenario_widget);
    
    // 하단 스플리터에 위젯 추가
    h_splitter_bottom->addWidget(motor_widget);
    h_splitter_bottom->addWidget(control_widget);
    
    // 메인 스플리터에 상/하단 스플리터 추가
    v_splitter->addWidget(h_splitter_top);
    v_splitter->addWidget(h_splitter_bottom);
    
    // 초기 크기 설정
    // 800 * 1000
    h_splitter_top->setSizes({300, 500});     // 좌상단(카메라) 500, 우상단(시나리오) 300
    h_splitter_bottom->setSizes({500, 300});  // 좌하단(모터) 400, 우하단(컨트롤) 400
    v_splitter->setSizes({300, 700});         // 상단영역 600, 하단영역 400
    
    // 메인 레이아웃에 스플리터 추가
    main_layout->addWidget(v_splitter);
    
    // 마진 제거
    main_layout->setContentsMargins(0, 0, 0, 0);
} 