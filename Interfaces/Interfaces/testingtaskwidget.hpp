#ifndef TESTINGTASKWIDGET_H
#define TESTINGTASKWIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QPushButton>
#include <QGroupBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QFormLayout>
#include <QString>
#include <QStringList>

class TestingTaskWidget {
private:
    //какие-то текстовые поля и прочие виджеты внутри
public:
    TestingTaskWidget();
    void showResult(QStringList);
    void showTaskText(QString);
    void showAnswers(QStringList);
};

#endif // TESTINGTASKWIDGET_H
