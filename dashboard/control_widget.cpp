#include "control_widget.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QSlider>

ControlWidget::ControlWidget(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: white;");
    
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    
    // 제목 라벨
    QLabel* label = new QLabel("SLAM", this);
    label->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(label);

    // 버튼 그리드 레이아웃
    QGridLayout* gridLayout = new QGridLayout();
    mainLayout->addLayout(gridLayout);

    // 버튼 생성 및 배치
    QPushButton* btnForward = new QPushButton("전진", this);
    QPushButton* btnBackward = new QPushButton("후진", this);
    QPushButton* btnLeft = new QPushButton("좌회전", this);
    QPushButton* btnRight = new QPushButton("우회전", this);
    QPushButton* btnStop = new QPushButton("정지", this);
    QPushButton* btnRotateLeft = new QPushButton("제자리\n좌회전", this);
    QPushButton* btnRotateRight = new QPushButton("제자리\n우회전", this);

    // 버든 버튼에 회색 배경 스타일 적용
    QString buttonStyle = "background-color: #D3D3D3;";
    btnForward->setStyleSheet(buttonStyle);
    btnBackward->setStyleSheet(buttonStyle);
    btnLeft->setStyleSheet(buttonStyle);
    btnRight->setStyleSheet(buttonStyle);
    btnStop->setStyleSheet(buttonStyle);
    btnRotateLeft->setStyleSheet(buttonStyle);
    btnRotateRight->setStyleSheet(buttonStyle);

    // 버튼 배치 (3x3 그리드)
    gridLayout->addWidget(btnRotateLeft, 0, 0);    // 좌상단
    gridLayout->addWidget(btnForward, 0, 1);       // 상단 중앙
    gridLayout->addWidget(btnRotateRight, 0, 2);   // 우상단
    
    gridLayout->addWidget(btnLeft, 1, 0);          // 중앙 좌측
    gridLayout->addWidget(btnStop, 1, 1);          // 중앙
    gridLayout->addWidget(btnRight, 1, 2);         // 중앙 우측
    
    gridLayout->addWidget(btnBackward, 2, 1);      // 하단 중앙
    
    // 높이 조절 슬라이더 추가
    QHBoxLayout* sliderLayout = new QHBoxLayout();
    QLabel* heightLabel = new QLabel("높이:", this);
    QSlider* heightSlider = new QSlider(Qt::Horizontal, this);
    
    // 슬라이더 설정
    heightSlider->setMinimum(0);
    heightSlider->setMaximum(100);
    heightSlider->setValue(50);
    
    sliderLayout->addWidget(heightLabel);
    sliderLayout->addWidget(heightSlider);
    
    mainLayout->addLayout(sliderLayout);

    // 슬라이더 값 변경 시그널 연결
    connect(heightSlider, &QSlider::valueChanged, this, [](int value) {
        // 여기에 높이 조절 로직 추가
    });
} 