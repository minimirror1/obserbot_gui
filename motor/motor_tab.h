#ifndef MOTOR_TAB_H
#define MOTOR_TAB_H

#include <QWidget>

class QFrame;
class MoveWidget;

class MotorTab : public QWidget
{
    Q_OBJECT
public:
    explicit MotorTab(QWidget *parent = nullptr);

private:
    void setupUI();

protected:
    void resizeEvent(QResizeEvent* event) override;

    QFrame* leftWidget;
    MoveWidget* moveWidget;
};

#endif // MOTOR_TAB_H 