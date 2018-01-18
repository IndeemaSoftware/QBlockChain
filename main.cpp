#include <QCoreApplication>
#include <QDataStream>
#include <QDebug>
#include <QFile>

#include "eeblockchain.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    EEBlockChain lChain;
    lChain.setDifficulty(5);

    qDebug() << "Mining block 1..." << endl;
    lChain.addBlock(new EEBlock(1, "Block 1 Data"));

    qDebug() << "Mining block 2..." << endl;
    lChain.addBlock(new EEBlock(2, "Block 2 Data"));

    qDebug() << "Mining block 3..." << endl;
    lChain.addBlock(new EEBlock(3, "Block 3 Data"));

    qDebug() << "Is blockchain valid? " << lChain.isValid();

    return a.exec();
}
