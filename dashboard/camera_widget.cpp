#include "camera_widget.h"
#include <QVBoxLayout>
#include <QLabel>

CameraWidget::CameraWidget(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: #f0f0f0;");
    
    QVBoxLayout* layout = new QVBoxLayout(this);
    QLabel* label = new QLabel("Camera", this);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);
} 