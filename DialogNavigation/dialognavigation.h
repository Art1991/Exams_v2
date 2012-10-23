#ifndef DIALOGNAVIGATION_H
#define DIALOGNAVIGATION_H

#include <QObject>
#include <QDialog>
#include <QString>
#include <QStringList>


#include "../Interfaces/Dialogs/dialogs.hpp"

class KeyStorageNode;

class DialogNavigation : public QObject
{
    Q_OBJECT
public:
    explicit DialogNavigation(QObject *parent = 0);

    QDialog::DialogCode getDialogResult() const;
signals:
    
public slots:
    QString selectTestForLearning(const QStringList &tests);
    QString selectTestForExecuting(const QStringList &tests);

    KeyStorageNode selectTheoryForLearning(const QList<KeyStorageNode> &theoryNodes);
    KeyStorageNode selectTheoryForTestHelp(const QList<KeyStorageNode> &theoryNodes, const QList<KeyStorageNode> &practiceNodes);

private:
    QDialog::DialogCode dialogResult;
};

#endif // DIALOGNAVIGATION_H
