#include "eeblock.h"

#include <QCryptographicHash>
#include <QDateTime>
#include <QDebug>

EEBlock::EEBlock(int index, QString data, QString previouseHash, QObject *parent) : QObject(parent),
    mIndex(index),
    mTimeStamp(QDateTime::currentMSecsSinceEpoch()),
    mData(data.toUtf8()),
    mHash(""),
    mPreviouseHash(previouseHash.toUtf8()),
    mNonce(-1)
{

}

QString EEBlock::calculateHash()
{
    QByteArray lCode = QString().number(mIndex).toUtf8() + QString().number(mTimeStamp).toUtf8() + mData + QString().number(mNonce).toUtf8() + mPreviouseHash;
    QByteArray lArray = QCryptographicHash::hash(lCode, QCryptographicHash::Sha256).toHex();

    return QString::fromStdString(lArray.data());
}

QString EEBlock::previouseHash() const
{
    return mPreviouseHash;
}

void EEBlock::setPreviouseHash(const QString &previouseHash)
{
    mPreviouseHash = previouseHash.toUtf8();
}

QString EEBlock::data() const
{
    return mData;
}

void EEBlock::setData(const QString &data)
{
    mData = data.toUtf8();
}

qint64 EEBlock::timeStamp() const
{
    return mTimeStamp;
}

void EEBlock::setTimeStamp(const qint64 &timeStamp)
{
    mTimeStamp = timeStamp;
}

int EEBlock::index() const
{
    return mIndex;
}

void EEBlock::setIndex(int index)
{
    mIndex = index;
}

QString EEBlock::hash() const
{
    return mHash;
}

void EEBlock::setHash(const QString &hash)
{
    mHash = hash.toUtf8();
}

void EEBlock::mineBlock(int difficulty) {
    QString lString;
    for (int i = 0; i < difficulty; ++i) {
        lString.append("0");
    }

    do {
        mNonce++;
        mHash = this->calculateHash().toUtf8();
//        qDebug() << "-------";
//        qDebug() << mHash.mid(0, difficulty);
//        qDebug() << lString;
    } while (mHash.mid(0, difficulty) != lString);

    qDebug() << "Block mined: " << mHash << endl;
}
