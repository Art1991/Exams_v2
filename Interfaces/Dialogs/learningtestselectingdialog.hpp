#ifndef LEARNINGTESTSELECTINGDIALOG_H
#define LEARNINGTESTSELECTINGDIALOG_H

#include <QDialog>
#include <QStringList>
#include <QString>

namespace Ui {
    class LearningTestSelectingDialog;
}

class LearningTestSelectingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LearningTestSelectingDialog(QWidget *parent = 0);
    ~LearningTestSelectingDialog();

    void setTestsData(const QStringList &tests);        // передаем комбинацию: title|version - данная комбинация считается уникальной.
    QString getSelectedTest();

private slots:
    void on_canselPushButton_clicked();

    void on_okPushButton_clicked();

private:
    Ui::LearningTestSelectingDialog *ui;
};

#endif // LEARNINGTESTSELECTINGDIALOG_H
