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
    //�����-�� ��������� ���� � ������ ������� ������
public:
    TestingTaskWidget();

    void showTaskText(QString);
    void showAnswers(QStringList);
};

#endif // TESTINGTASKWIDGET_H
