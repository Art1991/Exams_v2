#ifndef TESTINGTASKWIDGET_H
#define TESTINGTASKWIDGET_H

#include <QMessageBox>
#include <QWidget>
#include <QToolButton>
#include <QPushButton>
#include <QGroupBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QFormLayout>
#include <QString>
#include <QStringList>
#include "testingwidget.hpp"
#include "../../Logic/testinglogic.hpp"

class TestingTaskWidget : public QWidget {
    Q_OBJECT

private:

public:
    TestingWidget* twptr;
    TestingLogic* tlptr;
    TestingTaskWidget();
    void showResult(QStringList);
    void showTaskText(QStringList, QString);
    void showTaskText(QString);
    void showPicture(QString);
    void showAnswers(QStringList);
    void toFinishCount();
    void toReckon();
    void dumpingOfAnswers();
};

#endif // TESTINGTASKWIDGET_H
