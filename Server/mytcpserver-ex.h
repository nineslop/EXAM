#ifndef MYSERVER_H
#define MYSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>


class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();
    //void slotReadClient();
private:
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
    int server_status;
};

#endif // MYSERVER_Hs







