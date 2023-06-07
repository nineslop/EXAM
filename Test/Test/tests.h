
#ifndef TESTS_H
#define TESTS_H


#include <QDialog>
#include <QTest>
#include "../Examproga_07_06_23/mytcpserver-ex.h"

class Tests : public QObject
{
    Q_OBJECT

public:
    Tests(QWidget *parent = nullptr);
    ~Tests();

private slots:

    void test1();

};

#endif // TESTS_H
