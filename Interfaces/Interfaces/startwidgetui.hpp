#ifndef STARTWIDGETUI_H
#define STARTWIDGETUI_H

#include <QWidget>

namespace Ui {
class StartWidgetUI;
}

class StartWidgetUI : public QWidget
{
    Q_OBJECT

signals:
    void settingsJumpRequest();
    void extendedTheoryJumpRequest();
    void reviewedTestLEarningRequest();
    void exitJumpRequest();
    void testingJumpRequest();

public:
    explicit StartWidgetUI(QWidget *parent = 0);
    ~StartWidgetUI();
    
private slots:
    void on_settingsPushButton_clicked();

    void on_startTestPushButton_clicked();

    void on_extendedTheoryPushButton_clicked();


    //вот эта
    void on_testPreparingPushPutton_clicked();

    void on_exitPushButton_clicked();

private:
    Ui::StartWidgetUI *ui;
};

#endif // STARTWIDGETUI_H
