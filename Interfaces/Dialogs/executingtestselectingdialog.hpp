#ifndef EXECUTINGTESTSELECTINGDIALOG_H
#define EXECUTINGTESTSELECTINGDIALOG_H

#include <QDialog>
#include <QStringList>
#include <QString>

namespace Ui {
class ExecutingTestSelectingDialog;
}

class ExecutingTestSelectingDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ExecutingTestSelectingDialog(QWidget *parent = 0);
    ~ExecutingTestSelectingDialog();

    void setTestsData(const QStringList &tests);        // передаем комбинацию: title|version - данная комбинация считается уникальной.
    QString getSelectedTest();

    bool isWithHelp();
    bool isMixed();

    bool isWithoutHelp();
    bool isUsual();
    
private slots:
    void on_canselPushButton_clicked();

    void on_okPushButton_clicked();

private:
    Ui::ExecutingTestSelectingDialog *ui;
    bool withHelp;
    bool usual;
};

#endif // EXECUTINGTESTSELECTINGDIALOG_H
