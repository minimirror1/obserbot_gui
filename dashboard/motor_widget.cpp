#include "motor_widget.h"
#include "motor_status_box.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QScrollArea>
#include <QDebug>
#include <QDir>

MotorWidget::MotorWidget(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: #d0d0d0;");
    
    QVBoxLayout* main_layout = new QVBoxLayout(this);
    
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

void MotorWidget::loadMotorInfo()
{
    QFile file("config/motor_info.json");
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Could not open config/motor_info.json");
        qDebug() << "Current path:" << QDir::currentPath();  // 현재 경로 출력
        return;
    }
    
    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray motors = doc.array();
    
    for(const QJsonValue& motor : motors) {
        QJsonObject motor_obj = motor.toObject();
        QString id = motor_obj["id"].toString();
        QString nickname = motor_obj["nickname"].toString();
        
        MotorStatusBox* box = new MotorStatusBox(id, nickname, this);
        motor_boxes.append(box);
        qDebug() << "Loaded motor: " << id << " - " << nickname;
    }
} 