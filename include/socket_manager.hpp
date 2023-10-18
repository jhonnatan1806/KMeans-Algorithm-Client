#ifndef SOCKET_MANAGER_HPP
#define SOCKET_MANAGER_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class SocketManager
{
public:
    SocketManager(const char *serverIP, int serverPort);
    ~SocketManager();

    bool connectToServer();
    void sendData(std::string message);
    std::string receiveData();

private:
    int clientSocket;
    sockaddr_in serverAddr;
};

#endif // SOCKET_MANAGER_HPP
