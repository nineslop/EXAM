#include "mytcpserver-ex.h"
#include <QDebug>
#include <QCoreApplication>

MyTcpServer::~MyTcpServer()
{
    //mTcpSocket->close();
    mTcpServer->close();
    server_status=0;
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    if(server_status==1){
        mTcpSocket = mTcpServer->nextPendingConnection();
        mTcpSocket->write("Hello, World!!! I am echo server!\r\n");
        connect(mTcpSocket, &QTcpSocket::readyRead,
                this,&MyTcpServer::slotServerRead);
        connect(mTcpSocket,&QTcpSocket::disconnected,
                this,&MyTcpServer::slotClientDisconnected);
    }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket* socket = (QTcpSocket*)sender();
    int desc = socket->socketDescriptor();
    QByteArray array;
    QString tmp;
    while(mTcpSocket->bytesAvailable()>0)
    {
        array=(socket->readLine());
        tmp.append(array);
    }
    array.clear();
    array.append(tmp.toUtf8());
    //array.append(parsing(tmp).toUtf8())
    mTcpSocket->write(array);
}

void MyTcpServer::slotClientDisconnected(){
    mTcpSocket->close();
}

void swapValues(double &x, double &y)
{
    double temp = x;
    x = y;
    y = temp;
}

QVector<double> siftArray(QVector<double> list, int index, int maxIndex)
{
    int left = index;
    int right = 2 * index + 1;

    while (right <= maxIndex)
    {
        if (right < maxIndex && list[right] > list[right + 1])
        {
            right++;
        }

        if (list[left] > list[right])
        {
            swapValues(list[left], list[right]);
            left = right;
            right = 2 * left + 1;
        }
        else
        {
            break;
        }
    }

    return list;
}

QVector<double> heapSort(QVector<double> list, int step)
{
    int size = list.size();
    QVector<double> sortedList = list;

    // build a heap
    for (int i = size / 2; i >= 0; i--)
    {
        sortedList = siftArray(sortedList, i, size - 1);
    }

    // sort the array
    for (int j = size - 1; j >= 1; j--)
    {
        swapValues(sortedList[0], sortedList[j]);

        if (j == step)
        {
            return sortedList; // return the list at the step requested
        }

        sortedList = siftArray(sortedList, 0, j - 1);
    }

    return sortedList;
}



