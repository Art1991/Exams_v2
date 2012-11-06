#ifndef DIALOGNAVIGATION_H
#define DIALOGNAVIGATION_H

#include <QObject>
#include <QDialog>
#include <QString>
#include <QStringList>


#include "../Interfaces/Dialogs/executingtestselectingdialog.hpp"
#include "../Interfaces/Dialogs/extendedtheoryselectingdialog.hpp"
#include "../Interfaces/Dialogs/learningtestselectingdialog.hpp"
#include "../Interfaces/Dialogs/personalizationdialog.hpp"
#include "../Interfaces/Dialogs/testhelpselectingdialog.hpp"
#include "../Interfaces/Dialogs/testresultsdialog.hpp"

class KeyStorageNode;

class DialogNavigation : public QObject
{
    Q_OBJECT
public:
    explicit DialogNavigation(QObject *parent = 0);

    const int getDialogResult() const;
signals:
    
public slots:
    QString selectTestForLearning(const QStringList &tests);
    QString selectTestForExecuting(const QStringList &tests);

    KeyStorageNode selectTheoryForLearning(const QList<KeyStorageNode> &theoryNodes);
    KeyStorageNode selectTheoryForTestHelp(const QList<KeyStorageNode> &theoryNodes, const QList<KeyStorageNode> &practiceNodes);

private:
    int dialogResult;
};

#endif // DIALOGNAVIGATION_H
