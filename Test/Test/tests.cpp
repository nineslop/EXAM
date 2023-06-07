#include "Tests.h"

Tests::Tests(QWidget *parent)
    : QObject(parent)
{
}

Tests::~Tests()
{
}

void Tests::test1()
{
    QVector<QVector<int>> G = {{1,1,0,0},{1,0,1,1},{0,0,0,1},{0,1,1,0}};
    QVERIFY(solve(G) = "|0 1 1 1|1 0 1 0|1 1 0 1|1 0 1 0|");
}

