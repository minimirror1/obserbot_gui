#ifndef MOTOR_ANGLE_VIEWER_H
#define MOTOR_ANGLE_VIEWER_H

#include <QWidget>
#include <QPainter>
#include <QtMath>

class MotorAngleViewer : public QWidget {
public:
    MotorAngleViewer(QWidget* parent = nullptr) : QWidget(parent), currentAngle(0) {
        setMinimumSize(100, 100);
    }
    
    void setAngle(double angle) {
        currentAngle = angle;
        update();
    }
    
protected:
    void paintEvent(QPaintEvent*) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        
        // 중심점 계산
        int centerX = width() / 2;
        int centerY = height() / 2;
        int radius = qMin(width(), height()) / 2 - 10;
        
        // 검은색 원 그리기
        painter.setPen(QPen(Qt::black, 2));
        painter.drawEllipse(QPoint(centerX, centerY), radius, radius);
        
        // 빨간색 선 그리기 (현재 각도 표시)
        painter.setPen(QPen(Qt::red, 2));
        double angleRad = qDegreesToRadians(-currentAngle);
        int lineEndX = centerX + radius * qCos(angleRad);
        int lineEndY = centerY - radius * qSin(angleRad);
        painter.drawLine(centerX, centerY, lineEndX, lineEndY);
    }
    
private:
    double currentAngle;
};

#endif // MOTOR_ANGLE_VIEWER_H