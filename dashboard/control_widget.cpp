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
    QPushButton* btnXPlus = new QPushButton("X+", this);
    QPushButton* btnXMinus = new QPushButton("X-", this);
    QPushButton* btnYPlus = new QPushButton("Y+", this);
    QPushButton* btnYMinus = new QPushButton("Y-", this);
    QPushButton* btnZPlus = new QPushButton("Z+", this);
    QPushButton* btnZMinus = new QPushButton("Z-", this);
    QPushButton* btnHome = new QPushButton("Home", this);
    QPushButton* btnZHome = new QPushButton("ZHome", this);
    // 버튼 스타일 수정
    QString buttonStyle = "QPushButton {"
                        "   background-color: #333333;"
                        "   color: white;"
                        "   border: none;"
                        "   border-radius: 4px;"
                        "   padding: 8px;"
                        "   min-width: 20px;"
                        "   min-height: 20px;"
                        "}"
                        "QPushButton:pressed {"
                        "   background-color: #444444;"
                        "}";

    btnXPlus->setStyleSheet(buttonStyle);
    btnXMinus->setStyleSheet(buttonStyle);
    btnYPlus->setStyleSheet(buttonStyle);
    btnYMinus->setStyleSheet(buttonStyle);
    btnZPlus->setStyleSheet(buttonStyle);
    btnZMinus->setStyleSheet(buttonStyle);
    btnHome->setStyleSheet(buttonStyle);
    btnZHome->setStyleSheet(buttonStyle);

    // 버튼 배치 (이미지와 같은 레이아웃)
    gridLayout->addWidget(btnYPlus, 0, 1);        // 상단 중앙
    gridLayout->addWidget(btnZPlus, 0, 3);        // 상단 우측

    gridLayout->addWidget(btnXMinus, 1, 0);       // 중앙 좌측
    gridLayout->addWidget(btnHome, 1, 1);         // 중앙
    gridLayout->addWidget(btnXPlus, 1, 2);       // 중앙 좌측
    gridLayout->addWidget(btnZHome, 1, 3);         // 중앙 (두 번째 홈 버튼)


    gridLayout->addWidget(btnYMinus, 2, 1);       // 중앙 좌측     
    gridLayout->addWidget(btnZMinus, 2, 3);       // 중앙 우측    
    

    // 그리드 레이아웃의 간격 조정
    gridLayout->setSpacing(4);  // 버튼 사이의 간격을 좁게 설정

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