#include "extendedtheoryselectingdialog.hpp"
#include "ui_extendedtheoryselectingdialog.h"

ExtendedTheorySelectingDialog::ExtendedTheorySelectingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExtendedTheorySelectingDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint);

    ui->treeWidgetChangeTheme->setColumnCount(1);
}

ExtendedTheorySelectingDialog::~ExtendedTheorySelectingDialog()
{
    delete ui;
}

void ExtendedTheorySelectingDialog::setTheoryNodes(const QList<KeyStorageNode> &theoryNodes)
{
    nodes = theoryNodes;

    QTreeWidgetItem *root = new QTreeWidgetItem();

    for (int i = 0; i < theoryNodes.length(); i++)
    {
        KeyStorageNode currentNode = theoryNodes.at(i);

        QList<Key> keys = currentNode.getInnerKeys();

        for (int j = 0; j < keys.length(); j++)
        {
            Key currentKey = keys.at(j);
            addKey(root, currentKey, currentNode.getPluginName(), i);
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

KeyStorageNode ExtendedTheorySelectingDialog::getSelectedNode() const
{
    int nodeId = ui->treeWidgetChangeTheme->currentItem()->data(0, Qt::UserRole).toInt();

    if (nodeId == -1)
    {
        //return KeyStorageNode(); исправить!
    }

    return nodes.at(nodeId);

}

void ExtendedTheorySelectingDialog::on_okPushButton_clicked()
{
    this->accept();
}

void ExtendedTheorySelectingDialog::on_canselPushButton_clicked()
{
    this->reject();
}

void ExtendedTheorySelectingDialog::addKey(QTreeWidgetItem *root, const Key &key, const QString &title, const uint nodeId)
{
    Key rootKey(root->text(0).split(" ").at(0));


    if (rootKey == key)
    {
        QTreeWidgetItem *newNode = new QTreeWidgetItem(root);

        newNode->setText(0, key.getKey() + " - " + title);
        newNode->setData(0, Qt::UserRole, nodeId);

        return;
    }

    for (int i = 0; i < root->childCount(); i++)
    {
        if (root->child(i)->text(0).contains(" "))
        {
            continue;
        }
        Key currentKey(root->child(i)->text(0).split(" ").at(0));

        if ((currentKey.isParentFor(key)) || (currentKey == key))
        {
            QTreeWidgetItem *newRoot = root->child(i);
            addKey(newRoot, key, title, nodeId);

            return;
        }
    }

    // иначе - среди узлов нет родителей, нужно создать свой ключ

    QList<int> rootLevels = rootKey.getLevels();
    QList<int> keyLevels = key.getLevels();


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
    newNode->setData(0, Qt::UserRole, -1);

    addKey(newNode, key, title, nodeId);


}
