#ifndef EXTENDEDTHEORYSELECTINGDIALOG_H
#define EXTENDEDTHEORYSELECTINGDIALOG_H

#include <QDialog>
#include <QList>
#include <QPair>
#include <QString>
#include <QStringList>

#include "../KeyStorage/key.hpp"
#include "../KeyStorage/keystoragenode.hpp"

namespace Ui {
    class ExtendedTheorySelectingDialog;
}

class ExtendedTheorySelectingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExtendedTheorySelectingDialog(QWidget *parent = 0);
    ~ExtendedTheorySelectingDialog();

    void setTheoryNodes(const QList<KeyStorageNode> &theoryNodes);
    KeyStorageNode getSelectedNode() const;

private slots:
    void on_okPushButton_clicked();

    void on_canselPushButton_clicked();

private:
    Ui::ExtendedTheorySelectingDialog *ui;

    void makeTree(const QList<Key> &nodes);
};

#endif // EXTENDEDTHEORYSELECTINGDIALOG_H
