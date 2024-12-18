#ifndef MOTOR_STATUS_BOX_H
#define MOTOR_STATUS_BOX_H

#include <QWidget>
#include <QLabel>

class MotorStatusBox : public QWidget
{
    Q_OBJECT
public:
    explicit MotorStatusBox(const QString& id, const QString& nickname, QWidget *parent = nullptr);
    void updatePosition(double position);  // 위치/각도 업데이트

private:
    QLabel* id_label;
    QLabel* nickname_label;
    QLabel* position_label;
};

#endif // MOTOR_STATUS_BOX_H 