#ifndef KEY_HPP
#define KEY_HPP

#include <QList>

class Key
{

public:
    enum KeyType {
        innerCode,
        outerCode,
        null
    };

    Key();
    Key(const QString &_code, const KeyType &_type);

    bool operator== (const Key &value) const;

    const QString getKey() const;
    const KeyType getKeyType() const;

    bool isChildrenFor(const Key &value) const;
    bool isParentFor(const Key &value) const;
    bool isNeighborFor(const Key &value) const;
    QList<int> toLevels(const QString &code);

    static KeyType strToEnum(const QString &str);
    static QString enumToStr(Key::KeyType type);
private:
    QList<int> levels;
    KeyType type;
};

#endif // KEY_HPP
