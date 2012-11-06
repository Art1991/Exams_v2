#include "dialognavigation.h"

DialogNavigation::DialogNavigation(QObject *parent) :
    QObject(parent)
{
    dialogResult = QDialog::Rejected;
}

const int DialogNavigation::getDialogResult() const
{
    return dialogResult;
}

QString DialogNavigation::selectTestForLearning(const QStringList &tests)
{
    LearningTestSelectingDialog dialog;
    dialog.setTestsData(tests);

    dialogResult = dialog.exec();

    return dialog.getSelectedTest();
}

QString DialogNavigation::selectTestForExecuting(const QStringList &tests)
{
    ExecutingTestSelectingDialog dialog;
    dialog.setTestsData(tests);

    dialogResult = dialog.exec();

    return dialog.getSelectedTest();
}

KeyStorageNode DialogNavigation::selectTheoryForLearning(const QList<KeyStorageNode> &theoryNodes)
{
    ExtendedTheorySelectingDialog dialog;
    dialog.setTheoryNodes(theoryNodes);

    dialogResult = dialog.exec();

    return dialog.getSelectedNode();
}

KeyStorageNode DialogNavigation::selectTheoryForTestHelp(const QList<KeyStorageNode> &theoryNodes, const QList<KeyStorageNode> &practiceNodes)
{
    TestHelpSelectingDialog dialog;
    dialog.setNodes(theoryNodes, practiceNodes);

    dialogResult = dialog.exec();

    return dialog.getSelectedKey();
}
