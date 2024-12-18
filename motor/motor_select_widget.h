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
    const QList<MotorSelectBox*>& getMotorBoxes() const { return motor_boxes; }

private slots:
    void handleBoxSelection(MotorSelectBox* selected_box);

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    void loadMotorInfo();
    void updateGridLayout();
    QList<MotorSelectBox*> motor_boxes;
    MotorSelectBox* current_selected_box = nullptr;

};

#endif // MOTOR_SELECT_WIDGET_H 