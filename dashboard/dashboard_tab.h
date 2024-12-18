#ifndef DASHBOARD_TAB_H
#define DASHBOARD_TAB_H

#include <QWidget>
#include "camera_widget.h"
#include "scenario_widget.h"
#include "motor_widget.h"
#include "control_widget.h"

class DashboardTab : public QWidget
{
    Q_OBJECT
public:
    explicit DashboardTab(QWidget *parent = nullptr);

private:
    CameraWidget* camera_widget;
    ScenarioWidget* scenario_widget;
    MotorWidget* motor_widget;
    ControlWidget* control_widget;
};

#endif // DASHBOARD_TAB_H 