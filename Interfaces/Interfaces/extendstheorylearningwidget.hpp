#ifndef EXTENDSTHEORYLEARNINGWIDGET_H
#define EXTENDSTHEORYLEARNINGWIDGET_H

#include <QWidget>
#include <QList>
#include <QString>

//#include "../DataClasses/key.hpp"
class Key;

namespace Ui {
    class ExtendsTheoryLearningWidget;
}

class ExtendsTheoryLearningWidget : public QWidget
{
    Q_OBJECT

signals:
    void menuJumpRequest();

public:
    explicit ExtendsTheoryLearningWidget(QWidget *parent = 0);
    ~ExtendsTheoryLearningWidget();

    void setTheoryKeys(const QList<Key> &keys);

private slots:
    void on_exitPushButton_clicked();

private:
    Ui::ExtendsTheoryLearningWidget *ui;
};

#endif // EXTENDSTHEORYLEARNINGWIDGET_H
