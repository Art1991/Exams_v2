#include "extendedtheoryselectingdialog.hpp"
#include "ui_extendedtheoryselectingdialog.h"

ExtendedTheorySelectingDialog::ExtendedTheorySelectingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExtendedTheorySelectingDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SubWindow | Qt::FramelessWindowHint);
}

ExtendedTheorySelectingDialog::~ExtendedTheorySelectingDialog()
{
    delete ui;
}

void ExtendedTheorySelectingDialog::setTheoryNodes(const QList<KeyStorageNode> &theoryNodes)
{
    for (uint i = 0; i < theoryNodes.length(); i++)
    {
        QList<Key>
        theoryNodes.at(i).
    }
}

void ExtendedTheorySelectingDialog::on_okPushButton_clicked()
{
    this->accept();
}

void ExtendedTheorySelectingDialog::on_canselPushButton_clicked()
{
    this->reject();
}

void ExtendedTheorySelectingDialog::makeTree(const QList<Key> &keys)
{
    QList<QPoint> usedLevels;   // x - значение, y - глубина


    ui->treeWidgetChangeTheme->clear();

    for (uint i = 0; i < keys.length(); i++)
    {
        QList<int> levels = keys.at(i).toLevels();

        QTreeWidgetItem *topLevelItem = new QTreeWidgetItem(ui->treeWidgetChangeTheme);
        topLevelItem->setText();

        for (uint j = 1; j < levels.length(); i++)
        {
            tree[levels.at(0)].append(levels.at(j));
        }
    }

    // выводим его в интерфейс
/*
    for (uint i = 0; i < tree.size(); i++)
    {
        QTreeWidgetItem *topLevelItem = new QTreeWidgetItem();
        QString key;
        if (tree[i].length() == 0)
        {
            continue;
        }

        for (int j = 0; j < tree[i].length(); j++)
        {
            key += QString::number(tree[i].at(j)) + ".";

            QString tmpKey = key;
            tmpKey.remove(tmpKey.length() - 2, 1);

            QTreeWidgetItem *currentLevelItem = new QTreeWidgetItem();
        }
    }
*/
    ui->treeWidgetChangeTheme->clear();

    ui->treeWidgetChangeTheme->addTopLevelItem(new Q);
}

bool ExtendedTheorySelectingDialog::findKeyInUITree(const QString &key)
{

}

void ExtendedTheorySelectingDialog::addNode(const KeyStorageNode &node)
{
    QList<Key> keys = node.getInnerKeys();

    for (uint i = 0; i < keys.length(); i++)
    {
        Key key = keys.at(i);


    }
}
