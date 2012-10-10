#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMouseEvent>

#include "startwidgetui.hpp"
#include "testpreparingwidget.hpp"
#include "extendstheorylearningwidget.hpp"
#include "testingwidget.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    virtual void mousePressEvent(QMouseEvent *event);
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
