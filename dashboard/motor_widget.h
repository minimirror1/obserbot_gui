#ifndef MOTOR_WIDGET_H
#define MOTOR_WIDGET_H

#include <QWidget>
#include <QVector>
#include "motor_status_box.h"

class MotorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MotorWidget(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    void loadMotorInfo();  // JSON 파일에서 모터 정보 로드
    QVector<MotorStatusBox*> motor_boxes;  // 모터 상태 박스들
    void updateGridLayout();
};

#endif // MOTOR_WIDGET_H 