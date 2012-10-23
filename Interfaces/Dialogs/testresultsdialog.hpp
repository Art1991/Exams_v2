#ifndef TESTRESULTSDIALOG_H
#define TESTRESULTSDIALOG_H

#include <QDialog>
#include <QList>

class DialogTestResults;

namespace Ui {
    class TestResultsDialog;
}

class TestResultsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TestResultsDialog(QWidget *parent = 0);
    ~TestResultsDialog();

    void setTestResults(const DialogTestResults &results);

private slots:
    void on_canselPushButton_clicked();

    void on_okPushButton_clicked();

private:
    Ui::TestResultsDialog *ui;
};

#endif // TESTRESULTSDIALOG_H
