#include "move_widget.h"
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QTableWidget>
#include <QTimer>

MoveWidget::MoveWidget(QWidget *parent) : QWidget(parent)
{
    setupUI();
}

void MoveWidget::setupUI()
{
    mainLayout = new QVBoxLayout(this);
    
    createIdAndNameSection();
    createMotorAngleViewer();
    
    currentAngle = 0;
    rotationTimer = new QTimer(this);
    connect(rotationTimer, &QTimer::timeout, this, &MoveWidget::updateAngle);
    rotationTimer->start(50);
    
    createParamSection();
    
    // Stop 버튼
    stopButton = new QPushButton("STOP", this);
    stopButton->setStyleSheet("background-color: red; color: white; font-weight: bold; font-size: 14px;");
    mainLayout->addWidget(stopButton);
    
    createJogGroup();
    createMoveGroup();
  
}

void MoveWidget::createIdAndNameSection()
{
    QHBoxLayout* idLayout = new QHBoxLayout();
    
    // ID 섹션
    QGroupBox* idBox = new QGroupBox("ID", this);
    idBox->setFixedWidth(80);
    idBox->setFixedHeight(60);
    QHBoxLayout* idBoxLayout = new QHBoxLayout(idBox);
    id_label = new QLabel("", this);
    id_label->setAlignment(Qt::AlignCenter);
    idBoxLayout->addWidget(id_label);
    
    // Name 섹션
    QGroupBox* nameBox = new QGroupBox("Name", this);
    nameBox->setFixedHeight(60);
    QHBoxLayout* nameBoxLayout = new QHBoxLayout(nameBox);
    name_label = new QLabel("", this);
    name_label->setAlignment(Qt::AlignCenter);
    nameBoxLayout->addWidget(name_label);
    
    idLayout->addWidget(idBox, 1);
    idLayout->addWidget(nameBox, 3);
    
    mainLayout->addLayout(idLayout);
}


void MoveWidget::createMotorAngleViewer()
{
    QGroupBox* angleBox = new QGroupBox("Angle Viewer", this);
    angleBox->setFixedHeight(130);
    
    QHBoxLayout* angleLayout = new QHBoxLayout(angleBox);

    angleViewer = new MotorAngleViewer(this);
    angleLayout->addWidget(angleViewer);

    positionLabel = new QLabel("Current Position : 876,216cnt", this);
    angleLayout->addWidget(positionLabel);
    
    mainLayout->addWidget(angleBox);

    
} 

void MoveWidget::createParamSection()
{
    QGridLayout* paramLayout = new QGridLayout();
    QStringList params = {"Acc:", "deAcc:", "Speed:", "StopAcc:"};
    for(int i = 0; i < params.size(); ++i) {
        paramLayout->addWidget(new QLabel(params[i], this), i, 0);
        
        QLineEdit* edit = new QLineEdit(this);
        edit->setFixedWidth(100);
        paramLayout->addWidget(edit, i, 1);
        
        paramMonitorLabels[i] = new QLabel("0", this);
        paramMonitorLabels[i]->setFixedWidth(80);
        paramMonitorLabels[i]->setStyleSheet("color: blue;");
        paramMonitorLabels[i]->setAlignment(Qt::AlignRight);
        paramLayout->addWidget(paramMonitorLabels[i], i, 2);
        
        paramLayout->addWidget(new QLabel("cnt/s^2", this), i, 3);
    }
    
    mainLayout->addLayout(paramLayout);
}

void MoveWidget::createJogGroup()
{
    QGroupBox* jogGroup = new QGroupBox("jog", this);
    QHBoxLayout* jogLayout = new QHBoxLayout(jogGroup);
    QLineEdit* jogSpeed = new QLineEdit(this);
    QPushButton* jogMinus = new QPushButton("-", this);
    QPushButton* jogPlus = new QPushButton("+", this);
    jogLayout->addWidget(jogSpeed);
    jogLayout->addWidget(new QLabel("cnt/s", this));
    jogLayout->addWidget(jogMinus);
    jogLayout->addWidget(jogPlus);
    
    mainLayout->addWidget(jogGroup);
}

void MoveWidget::createMoveGroup()
{
    QGroupBox* moveGroup = new QGroupBox("move", this);
    QHBoxLayout* moveLayout = new QHBoxLayout(moveGroup);
    QLineEdit* movePos = new QLineEdit(this);
    QPushButton* moveGo = new QPushButton("go", this);
    QPushButton* moveStop = new QPushButton("stop", this);
    moveLayout->addWidget(movePos);
    moveLayout->addWidget(new QLabel("cnt", this));
    moveLayout->addWidget(moveGo);
    moveLayout->addWidget(moveStop);
    
    mainLayout->addWidget(moveGroup);
}

void MoveWidget::updateAngle()
{
    currentAngle += 5;
    if (currentAngle >= 360) {
        currentAngle = 0;
    }
    angleViewer->setAngle(currentAngle);
}

void MoveWidget::setSelectedMotor(const QString& id, const QString& nickname)
{
    id_label->setText(id);
    name_label->setText(nickname);
}
