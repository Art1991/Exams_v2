#ifndef TESTPREPARINGWIDGET_H
#define TESTPREPARINGWIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class TestPreparingWidget;
}

class TestPreparingWidget : public QWidget
{
    Q_OBJECT

signals:
    void menuJumpRequest();
    void jumpToTaskRequest(const QString taskId);
    void jumpToTaskHelp(const QString taskId);
    void testExecutionRequst();
    void extendedTheoryRequest();

public:
    explicit TestPreparingWidget(QWidget *parent = 0);
    ~TestPreparingWidget();

    void setTaskCount(const int aCount, const int bCount, const int cCount);
    
private slots:
    void on_taskPushButton_clicked();


    void on_startTestPushButton_clicked();

    void on_extendedTheoryPushButton_clicked();

    void on_exitPushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::TestPreparingWidget *ui;

    int aCount;
    int bCount;
    int cCount;

    int navigationButtonCount;

    void navigationsInit();

    void showNavigationButtons(const int count, const QString &taskType = "A");
};

#endif // TESTPREPARINGWIDGET_H
