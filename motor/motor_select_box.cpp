#include "motor_select_box.h"
#include <QVBoxLayout>
#include <QPainter>
#include <QMouseEvent>

MotorSelectBox::MotorSelectBox(const QString& id, const QString& nickname, QWidget *parent)
    : QWidget(parent)
    , motor_id(id)
    , motor_nickname(nickname)
    , is_selected(false)
{
    setStyleSheet("background-color: #e8e8e8; border: 1px solid #999;");
    
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    
    id_label = new QLabel(QString("ID: %1").arg(id));
    nickname_label = new QLabel(nickname);
    position_label = new QLabel("Position: 0.0°");
    
    QString labelStyle = "QLabel { padding-left: 5px; }";
    id_label->setStyleSheet(labelStyle);
    nickname_label->setStyleSheet(labelStyle);
    position_label->setStyleSheet(labelStyle);
    
    id_label->setAlignment(Qt::AlignVCenter);
    nickname_label->setAlignment(Qt::AlignVCenter);
    position_label->setAlignment(Qt::AlignVCenter);
    
    id_label->setFixedSize(100, 25);
    nickname_label->setFixedSize(100, 25);
    position_label->setFixedSize(100, 25);
    
    layout->addWidget(id_label);
    layout->addWidget(nickname_label);
    layout->addWidget(position_label);
    
    setFixedSize(100, 75);
    
    // 마우스 클릭 추적을 위해 설정
    setMouseTracking(true);
}

void MotorSelectBox::updatePosition(double position)
{
    position_label->setText(QString("Position: %.2f°").arg(position));
}

void MotorSelectBox::setSelected(bool selected)
{
    is_selected = selected;
    update();  // 위젯 다시 그리기
}

void MotorSelectBox::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked(this);
    }
    QWidget::mousePressEvent(event);
}

void MotorSelectBox::paintEvent(QPaintEvent* event)
{
    QWidget::paintEvent(event);
    
    if (is_selected) {
        QPainter painter(this);
        painter.setPen(QPen(Qt::blue, 2));
        painter.drawRect(1, 1, width()-2, height()-2);
    }
} 