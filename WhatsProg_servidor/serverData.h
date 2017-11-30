#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdint.h>
#include "whatsprogData.h"
#include "winsocket.h"

using namespace std;

#define MAX_TIME 60
#define TIME_SEND_LOGIN 60

class User{
    private:
        string login;
        string password;
        tcp_winsocket s;
        list <Message> conversations; // organizar por remetente

    public:
        inline User(): login(""),password(""), s() {}
        bool isLoginValid();
        bool isPasswordValid();

        inline void setLogin(const string &l){login = l;}
        inline void setPassword(const string s){password = s;}
        inline string getLogin(){return login;}

        inline tcp_winsocket getSocket(){return s;}
        inline void setSocket(tcp_winsocket s){this->s = s;}

        
};

class Server{
private:
    list<User> users;
    list<Message> buffer;

    tcp_winsocket_server server_socket;
    winsocket_queue connected_sockets;

    

public:
    void openConnection(WINSOCKET_STATUS iResult);

    void statusThread(HANDLE tHandle);

    bool newUser(string login, string password, tcp_winsocket);
    bool isUserRepeated(User u);

    void checkConnectedClients();
    bool acceptSocket();

};
