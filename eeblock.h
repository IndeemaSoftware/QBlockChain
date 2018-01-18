#ifndef EEBLOCK_H
#define EEBLOCK_H

#include <QObject>

class EEBlockChain;

class EEBlock : public QObject
{
    Q_OBJECT

    friend EEBlockChain;
public:
    explicit EEBlock(int index, QString data, QString previouseHash="", QObject *parent = nullptr);

    QString hash() const;
    void setHash(const QString &hash);

    int index() const;
    void setIndex(int index);

    qint64 timeStamp() const;
    void setTimeStamp(const qint64 &timeStamp);

    QString data() const;
    void setData(const QString &data);

    QString previouseHash() const;
    void setPreviouseHash(const QString &previouseHash);

    void mineBlock(int difficulty);

private:
    QString calculateHash();

private:
    int mIndex;
    qint64 mTimeStamp;
    QByteArray mData;
    QByteArray mHash;
    QByteArray mPreviouseHash;
    int mNonce;
};

#endif // EEBLOCK_H
