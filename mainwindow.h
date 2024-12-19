#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAdminActionTriggered();
    void toggleAdminMode(bool checked);

private:
    Ui::MainWindow *ui;
    QTabWidget* tabWidget;
    QWidget* adminTab;
    bool isAdminMode = false;
    const QString adminPassword = "1234";
    QAction* adminAction;
};
#endif // MAINWINDOW_H
