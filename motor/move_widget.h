#ifndef MOVE_WIDGET_H
#define MOVE_WIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QHeaderView>
#include "motor_angle_viewer.h"
#include <QTimer>

class QVBoxLayout;
class QLabel;
class QComboBox;
class QPushButton;
class QLineEdit;

class MoveWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MoveWidget(QWidget *parent = nullptr);

private:
    void setupUI();
    void createIdAndNameSection();
    void createParamSection();
    void createJogGroup();
    void createMoveGroup();
    void createMotorAngleViewer();

    QVBoxLayout* mainLayout;
    QLabel* positionLabel;
    QComboBox* idCombo;
    QPushButton* stopButton;
    QLabel* paramMonitorLabels[4];  // 모터 파라미터 모니터링을 위한 라벨 배열 추가
    MotorAngleViewer* angleViewer;
    QTimer* rotationTimer;
    double currentAngle;

private slots:
    void updateAngle();
};

#endif // MOVE_WIDGET_H 