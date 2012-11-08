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
    
    // создаем слот для поимки сигнала из startwidgetlogic
public slots:
    void switchToTestPreparingWidget();
    // добавляем реализацию этого слота в MainWindow.cpp


private:
    Ui::MainWindow *ui;
    StartWidgetUI* swptr;
    TestPreparingWidget* tpwptr;
    ExtendsTheoryLearningWidget* etlwptr;
    TestingWidget* twptr;
public:
    StartWidgetUI* getStartWidgetUIPtr();
    TestPreparingWidget* getTestPreparingWidgetPtr();
    ExtendsTheoryLearningWidget* getExtendsTheoryLearningWidgetPtr();
    TestingWidget* getTestingWidgetPtr();
};

#endif // MAINWINDOW_H
