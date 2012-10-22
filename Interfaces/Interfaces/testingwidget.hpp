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
    
public:
    explicit TestingWidget(QWidget *parent = 0);
    ~TestingWidget();
    
private slots:
    void on_stopTestButton_clicked();

private:
    Ui::TestingWidget *ui;

    void navigationsInit();
    void answersAInit();
    void answersBInit();
    void answersCInit();
};

#endif // TESTINGWIDGET_H
