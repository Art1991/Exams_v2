#ifndef TESTHELPSELECTINGDIALOG_H
#define TESTHELPSELECTINGDIALOG_H

#include <QDialog>
#include <QList>
#include <QString>

class KeyStorageNode;

namespace Ui {
    class TestHelpSelectingDialog;
}

class TestHelpSelectingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TestHelpSelectingDialog(QWidget *parent = 0);
    ~TestHelpSelectingDialog();

    void setTheoryNodes(const QList<KeyStorageNode> &theoryNodes);
    void setPracticeNodes(const QList<KeyStorageNode> &practiceNodes);

    KeyStorageNode getSelectedKey() const;

private slots:
    void on_canselPushButton_clicked();

    void on_okPushButton_clicked();

private:
    Ui::TestHelpSelectingDialog *ui;
};

#endif // TESTHELPSELECTINGDIALOG_H
