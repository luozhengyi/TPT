#ifndef __LOGIN_H__
#define __LOGIN_H__
#include <sys/socket.h>  //socket api functions and structions(sockaddr)
#include <sys/types.h>	 //socket data types
#include <netinet/in.h>	 //sockaddr_in
#include <arpa/inet.h>	 //support ip addr convertion functions
#include <sys/ioctl.h>	 //support i/o controlling functions
#include <sys/poll.h>	 //support socket waitting test functions


class login
{
#define INVALID_SOCK -1
#define SOCKET_ERROR   -1
#define port 7887
#define addr "127.0.0.1"
	
typedef int SOCKET;

public:
	login();
	virtual ~login();

public:
	int start();

private:
	sockaddr_in addrSrv;
	SOCKET fd;
};



#endif //__LOGIN_H__
