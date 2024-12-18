#include "scenario_widget.h"
#include <QVBoxLayout>
#include <QLabel>

ScenarioWidget::ScenarioWidget(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: #e0e0e0;");
    
    QVBoxLayout* layout = new QVBoxLayout(this);
    QLabel* label = new QLabel("Scenario", this);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);
} 