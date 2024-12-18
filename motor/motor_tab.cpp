#include "motor_tab.h"
#include "move_widget.h"
#include "motor_select_widget.h"
#include <QHBoxLayout>
#include <QSplitter>
#include <QFrame>

MotorTab::MotorTab(QWidget *parent) : QWidget(parent)
{
    setupUI();
}

void MotorTab::setupUI()
{
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    QSplitter* splitter = new QSplitter(Qt::Horizontal, this);
    
    leftWidget = new QFrame(this);
    leftWidget->setFrameShape(QFrame::StyledPanel);
    
    QVBoxLayout* leftLayout = new QVBoxLayout(leftWidget);
    leftLayout->setContentsMargins(0, 0, 0, 0);
    
    moveWidget = new MoveWidget(this);
    MotorSelectWidget* motorSelectWidget = new MotorSelectWidget(this);
    
    for(auto* box : motorSelectWidget->getMotorBoxes()) {
        connect(box, &MotorSelectBox::motorSelected,
                moveWidget, &MoveWidget::setSelectedMotor);
    }
    
    leftLayout->addWidget(motorSelectWidget);
    
    splitter->addWidget(leftWidget);
    splitter->addWidget(moveWidget);
    
    QList<int> sizes;
    sizes << 500 << 300;
    splitter->setSizes(sizes);
    
    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 1);
    
    mainLayout->addWidget(splitter);
}

void MotorTab::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
}
  