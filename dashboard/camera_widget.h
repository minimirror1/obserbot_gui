#ifndef CAMERA_WIDGET_H
#define CAMERA_WIDGET_H

#include <QWidget>

class CameraWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CameraWidget(QWidget *parent = nullptr);
};

#endif // CAMERA_WIDGET_H 