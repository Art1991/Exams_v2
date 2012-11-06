#include "testhelpselectingdialog.hpp"
#include "ui_testhelpselectingdialog.h"

TestHelpSelectingDialog::TestHelpSelectingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestHelpSelectingDialog)
{
    ui->setupUi(this);

    ui->treeWidgetChangeTheme->setColumnCount(1);
}

TestHelpSelectingDialog::~TestHelpSelectingDialog()
{
    delete ui;
}

void TestHelpSelectingDialog::setNodes(const QList<KeyStorageNode> &theoryNodes, const QList<KeyStorageNode> &practiceNodes)
{
    this->theoryNodes = theoryNodes;
    this->practiceNodes = practiceNodes;
    showPracticeNodes();
}

KeyStorageNode TestHelpSelectingDialog::getSelectedKey() const
{
}

void TestHelpSelectingDialog::on_canselPushButton_clicked()
{
    this->reject();
}

void TestHelpSelectingDialog::on_okPushButton_clicked()
{
    this->accept();
}

void TestHelpSelectingDialog::addKey(QTreeWidgetItem *root, const Key &key, const QString &title, const uint nodeId, const int role)
{
    Key rootKey(root->text(0).split(" ").at(0), ((role == Qt::UserRole) ? Key::InnerCode : Key::OuterCode));

    if (rootKey == key)
    {
        QTreeWidgetItem *newNode = new QTreeWidgetItem(root);

        newNode->setText(0, key.getKey() + " - " + title);
        newNode->setData(0, role, nodeId);

        return;
    }

    for (int i = 0; i < root->childCount(); i++)
    {
        if (root->child(i)->text(0).contains(" "))
        {
            continue;
        }
        Key currentKey(root->child(i)->text(0).split(" ").at(0), ((role == Qt::UserRole) ? Key::InnerCode : Key::OuterCode));

        if ((currentKey.isParentFor(key)) || (currentKey == key))
        {
            QTreeWidgetItem *newRoot = root->child(i);
            addKey(newRoot, key, title, nodeId, role);

            return;
        }
    }

    // иначе - среди узлов нет родителей, нужно создать свой ключ

    QList<int> rootLevels = rootKey.toLevels();
    QList<int> keyLevels = key.toLevels();


    QString newKey;
    if (!((rootLevels.length() == 1) && (rootLevels.at(0) == 0)))
    {
        newKey = rootKey.getKey();
        newKey += "." + QString::number(keyLevels.at(rootLevels.length()), 10);
    }
    else
    {
        newKey = QString::number(keyLevels.at(0), 10);
    }

    QTreeWidgetItem *newNode = new QTreeWidgetItem(root);

    newNode->setText(0, newKey);
    newNode->setData(0, role, -1);

    addKey(newNode, key, title, nodeId, role);
}

void TestHelpSelectingDialog::showTheoryNodes()
{
    QTreeWidgetItem *root = new QTreeWidgetItem();

    for (int i = 0; i < theoryNodes.length(); i++)
    {
        KeyStorageNode currentNode = theoryNodes.at(i);

        QList<Key> keys = currentNode.getInnerKeys();

        for (int j = 0; j < keys.length(); j++)
        {
            Key currentKey = keys.at(j);
            addKey(root, currentKey, currentNode.getPluginName(), i, Qt::UserRole);
        }
    }

    ui->treeWidgetChangeTheme->clear();

    while (root->childCount() != 0)
    {
        ui->treeWidgetChangeTheme->addTopLevelItem(root->takeChild(0));
    }

    delete root;

    ui->treeWidgetChangeTheme->sortByColumn(0, Qt::AscendingOrder);
}

void TestHelpSelectingDialog::showPracticeNodes()
{
    QTreeWidgetItem *root = new QTreeWidgetItem();

    for (int i = 0; i < practiceNodes.length(); i++)
    {
        KeyStorageNode currentNode = practiceNodes.at(i);

        QList<Key> keys = currentNode.getOuterKeys();

        for (int j = 0; j < keys.length(); j++)
        {
            Key currentKey = keys.at(j);
            addKey(root, currentKey, currentNode.getPluginName(), i, Qt::UserRole + 1);
        }
    }

    ui->treeWidgetChangeTheme->clear();

    while (root->childCount() != 0)
    {
        ui->treeWidgetChangeTheme->addTopLevelItem(root->takeChild(0));
    }

    delete root;

    ui->treeWidgetChangeTheme->sortByColumn(0, Qt::AscendingOrder);
}

void TestHelpSelectingDialog::on_radioButtonTestAnalysis_clicked()
{
    showPracticeNodes();
}

void TestHelpSelectingDialog::on_radioButtonTheory_clicked()
{
    showTheoryNodes();
}
