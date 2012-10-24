#ifndef TESTHELPSELECTINGDIALOG_H
#define TESTHELPSELECTINGDIALOG_H

#include <QDialog>
#include <QList>
#include <QString>
#include <QTreeWidget>
#include <QTreeWidgetItem>

#include "../../KeyStorage/key.hpp"
#include "../../KeyStorage/keystoragenode.hpp"

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

    void setNodes(const QList<KeyStorageNode> &theoryNodes, const QList<KeyStorageNode> &practiceNodes);

    KeyStorageNode getSelectedKey() const;

private slots:
    void on_canselPushButton_clicked();

    void on_okPushButton_clicked();

    void on_radioButtonTestAnalysis_clicked();

    void on_radioButtonTheory_clicked();

private:
    Ui::TestHelpSelectingDialog *ui;

    QList<KeyStorageNode> theoryNodes;
    QList<KeyStorageNode> practiceNodes;

    void addKey(QTreeWidgetItem *root, const Key &key, const QString &title, const uint nodeId, const int role);
    void showTheoryNodes();
    void showPracticeNodes();
};

#endif // TESTHELPSELECTINGDIALOG_H
