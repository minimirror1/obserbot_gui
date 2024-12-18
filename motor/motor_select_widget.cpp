#include "motor_select_widget.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QScrollArea>
#include <QDebug>
#include <QDir>

MotorSelectWidget::MotorSelectWidget(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: #d0d0d0;");
    
    QVBoxLayout* main_layout = new QVBoxLayout(this);
    main_layout->setContentsMargins(0, 0, 0, 0);
    
    // 스크롤 가능한 영역 생성
    QScrollArea* scroll_area = new QScrollArea(this);
    QWidget* scroll_content = new QWidget;
    QGridLayout* grid_layout = new QGridLayout(scroll_content);
    
    // JSON 파일에서 모터 정보 로드
    loadMotorInfo();
    
    // 모터 박스들을 그리드에 배치 (4열로 설정)
    const int columns = 4;
    for(int i = 0; i < motor_boxes.size(); ++i) {
        int row = i / columns;
        int col = i % columns;
        grid_layout->addWidget(motor_boxes[i], row, col);
    }
    
    scroll_area->setWidget(scroll_content);
    scroll_area->setWidgetResizable(true);
    main_layout->addWidget(scroll_area);
}

void MotorSelectWidget::loadMotorInfo()
{
    QFile file("config/motor_info.json");
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Could not open config/motor_info.json");
        qDebug() << "Current path:" << QDir::currentPath();
        return;
    }
    
    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray motors = doc.array();
    
    for(const QJsonValue& motor : motors) {
        QJsonObject motor_obj = motor.toObject();
        QString id = motor_obj["id"].toString();
        QString nickname = motor_obj["nickname"].toString();
        
        MotorSelectBox* box = new MotorSelectBox(id, nickname, this);
        motor_boxes.append(box);
        qDebug() << "Loaded motor: " << id << " - " << nickname;
    }
}

void MotorSelectWidget::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    updateGridLayout();
}

void MotorSelectWidget::updateGridLayout()
{
    if (motor_boxes.isEmpty()) return;

    // 각 모터 박스의 기본 너비
    const int box_width = 100;
    // 스크롤 영역의 너비를 기준으로 최적의 컬럼 수 계산
    int available_width = this->width() - 30; // 스크롤바 여유 공간 고려
    int columns = qMax(1, available_width / box_width);
    
    // 그리드 ���이아웃 재구성
    QGridLayout* grid_layout = qobject_cast<QGridLayout*>(
        ((QWidget*)motor_boxes[0]->parent())->layout());
    
    if (grid_layout) {
        // 기존 위젯들을 그리드에서 제거
        for (auto* box : motor_boxes) {
            grid_layout->removeWidget(box);
        }
        
        // 새로운 컬럼 수로 재배치
        for(int i = 0; i < motor_boxes.size(); ++i) {
            int row = i / columns;
            int col = i % columns;
            grid_layout->addWidget(motor_boxes[i], row, col);
        }
    }
}
