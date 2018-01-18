#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "eeblock.h"

#include <QObject>

class EEBlockChain : public QObject
{
    Q_OBJECT
public:
    explicit EEBlockChain(QObject *parent = nullptr);

    void addBlock(EEBlock*);
    bool isValid();

    int difficulty() const;
    void setDifficulty(int difficulty);

private:
    void initChain();
private:
    QList<EEBlock*> mChain;
    int mDifficulty = 4;
};

#endif // BLOCKCHAIN_H
