#ifndef MOTOR_SELECT_BOX_H
#define MOTOR_SELECT_BOX_H

#include <QWidget>
#include <QLabel>

class MotorSelectBox : public QWidget
{
    Q_OBJECT
public:
    explicit MotorSelectBox(const QString& id, const QString& nickname, QWidget *parent = nullptr);
    void updatePosition(double position);  // 위치/각도 업데이트
    void setSelected(bool selected);  // 선택 상태 설정
    QString getId() const { return motor_id; }
    QString getNickname() const { return motor_nickname; }

signals:
    void clicked(MotorSelectBox* box);  // 클릭 시그널

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

private:
    QString motor_id;
    QString motor_nickname;
    QLabel* id_label;
    QLabel* nickname_label;
    QLabel* position_label;
    bool is_selected;
};

#endif // MOTOR_SELECT_BOX_H
