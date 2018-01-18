#include "eeblockchain.h"

EEBlockChain::EEBlockChain(QObject *parent) : QObject(parent)
{
    initChain();
}

void EEBlockChain::addBlock(EEBlock *block)
{
    QString lPreviouseHash = "";
    if (mChain.count() > 0) {
        lPreviouseHash = mChain.last()->hash();
    } else {
        initChain();
    }

    block->setPreviouseHash(lPreviouseHash);
    block->mineBlock(mDifficulty);
    mChain.append(block);
}

bool EEBlockChain::isValid()
{
    bool rIsValid = false;
    for (int i=1; i< mChain.count(); i++) {
        EEBlock *lPrBlock = mChain.at(i-1);
        EEBlock *lBlock = mChain.at(i);

        if (lBlock->hash() == lBlock->calculateHash()) {
            rIsValid = true;
        } else {
            rIsValid = false;
        }

        if (lBlock->previouseHash() == lPrBlock->hash()) {
            rIsValid = true;
        } else {
            rIsValid = false;
        }

    }

    return true;
}

void EEBlockChain::initChain()
{
    mChain.append(new EEBlock(mChain.count(), "Genesis Block"));
}

int EEBlockChain::difficulty() const
{
    return mDifficulty;
}

void EEBlockChain::setDifficulty(int difficulty)
{
    mDifficulty = difficulty;
}
