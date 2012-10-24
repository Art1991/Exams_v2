#ifndef ABSTRACTTESTTASK_H
#define ABSTRACTTESTTASK_H

#include <QString>
#include <QStringList>

#include "../KeyStorage/key.hpp"

class AbstractTestTask
{
public:
    AbstractTestTask();

    virtual const QString getTaskId() const = 0;
    const QStringList getInnerCodes() const;
    const QStringList getOuterCodes() const;

    bool isInnerCodeRepresent(const Key &key) const;
    bool isOuterCodeRepresent(const Key &key) const;

protected:

    QString taskId;

    QList<Key> keys;

};

#endif // ABSTRACTTESTTASK_H
