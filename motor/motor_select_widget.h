#ifndef MOTOR_SELECT_WIDGET_H
#define MOTOR_SELECT_WIDGET_H

#include <QWidget>
#include <QVector>
#include "motor_select_box.h"

class MotorSelectWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MotorSelectWidget(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    void loadMotorInfo();
    void updateGridLayout();
    QVector<MotorSelectBox*> motor_boxes;
};

#endif // MOTOR_SELECT_WIDGET_H 