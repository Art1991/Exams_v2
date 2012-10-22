#include <QtGui/QApplication>
#include <QFile>
#include <QTextCodec>

#include "serializators.hpp"
#include "keyserializator.hpp"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));

    QApplication a(argc, argv);

    ReviewedTestSerializator serializator;

    ReviewedTest test;
    KeySerializator l;

    try
    {

        l.loadKeys("c:\\textxml.xml", KeyStorageNode::Plugin);
        //test = serializator.loadTest("c:\\reviewedtest.xml");
    }
    catch (Exception err)
    {
        qDebug() << err.getErrorMessage();
    }
    qDebug() << "parsing complete";

    try
    {
        serializator.saveTest(test, "c:\\test1.xml");
    }
    catch (Exception err)
    {
        qDebug() << err.getErrorMessage();
    }
    qDebug() << "saving complete";

    return a.exec();
}
