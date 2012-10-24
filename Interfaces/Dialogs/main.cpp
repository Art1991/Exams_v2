#include <QtGui/QApplication>
#include <QTextCodec>
#include <QDebug>

#include "mainwindow.hpp"

#include "dialogs.hpp"
#include "key.hpp"
#include "keystoragenode.hpp"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));


    QApplication a(argc, argv);
    /*MainWindow w;
    w.show();*/
    QStringList l;

    Key k1("1.2.1", Key::innerCode);
    Key k2("1.2.2", Key::innerCode);
    Key k3("1.2.2.1", Key::innerCode);
    Key k4("1.3.1", Key::outerCode);
    Key k5("1.1", Key::outerCode);
    Key k6("2.1", Key::outerCode);

    QList<Key> keys1;
    keys1 << k1;
    keys1 << k2;
    keys1 << k3;

    QList<Key> keys2;
    keys2 << k2;
    keys2 << k3;
    keys2 << k4;

    QList<Key> keys3;
    keys3 << k4;
    keys3 << k5;
    keys3 << k6;
    keys3 << k1;

    KeyStorageNode n1(keys1, KeyStorageNode::Theory, "теория 1", "1.html", "");

    KeyStorageNode n2(keys2, KeyStorageNode::Theory, "теория 2", "2.html", "");

    KeyStorageNode n3(keys3, KeyStorageNode::Theory, "теория 3", "3.html", "");


    QList<KeyStorageNode> nodes;
    nodes << n1;
    nodes << n2;
    nodes << n3;




    TestHelpSelectingDialog dlg;

    dlg.setNodes(nodes, nodes);

    dlg.exec();

    return a.exec();
}
