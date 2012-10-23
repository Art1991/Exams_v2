#ifndef TESTINGWIDGET_H
#define TESTINGWIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QPushButton>
#include <QGroupBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QFormLayout>

namespace Ui {
class TestingWidget;
}

class TestingWidget : public QWidget
{
    Q_OBJECT

signals:
    void menuJumpRequest();
    void startTestRequest();
    void finishTestRequest();

    void jumpToTaskRequest(const QString taskId);
    void jumpToTaskHelp(const QString taskId);
    
public:
    explicit TestingWidget(QWidget *parent = 0);
    ~TestingWidget();

    void setTaskCount(const int aCount, const int bCount, const int cCount);

    void hideHelpButtons();
    void showHelpButtons();

private slots:
    void on_startTestButton_clicked();

    void on_stopTestButton_clicked();

    void on_exitPushButton_clicked();

    void on_taskPushButton_clicked();
    void on_taskHelpPushButton_clicked();

    void on_taskGroupSwitched();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::TestingWidget *ui;

    int aCount;
    int bCount;
    int cCount;

    int navigationButtonCount;

    void navigationsInit();
    void answersAInit();
    void answersBInit();
    void answersCInit();

    void showNavigationButtons(const int count, const QString &taskType = "A");
    void showAAnswersFields(const int count);
    void showBAnswersFields(const int count);
    void showCAnswersFields(const int count);
};

#endif // TESTINGWIDGET_H
