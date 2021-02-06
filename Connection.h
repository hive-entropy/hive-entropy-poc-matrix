#ifndef CONNECTION_H
#define CONNECTION_H

#include <sys/socket.h>
#include <sys/un.h>
#include <string>

using namespace std;

class Connection
{
private:
    bool isServer;
    sockaddr_un socket;
public:
    Connection(string path, bool isServer);
    ~Connection();
    void send(string message);
    string receive();
};


#endif