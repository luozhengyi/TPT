#include "login.h"
#include <unistd.h>	//close()
#include <string.h>	//bzero()

login::login()
{
}

login::~login()
{
}


int login::start()
{
	int iRet = 0;
	do
	{
		if(INVALID_SOCK != fd)
		{
			close(fd);
			fd = INVALID_SOCK;
		}
		fd = socket(AF_INET,SOCK_STREAM,0);	
		if(fd == INVALID_SOCK)
		{
			iRet = -5;	//create socket fd failed
			break;
		}

		bzero(&addrSrv,sizeof(sockaddr_in));
		addrSrv.sin_family = AF_INET;
		addrSrv.sin_port = htons(port);
		addrSrv.sin_addr.s_addr = htonl(INADDR_ANY);
		
		if( SOCKET_ERROR == bind(fd,(sockaddr*)&addrSrv,sizeof(sockaddr_in)))
		{
			iRet = -6;	//bind failed
			break;
		}
		
		if(SOCKET_ERROR == listen(fd,10))
		{
			iRet = -7;	//listen setup failed
			break;
		}

		sockaddr_in addrClient;
		int len = 0;
		while(1)
		{
			SOCKET clientfd = INVALID_SOCK;
			clientfd = accept(fd,(sockaddr*)&addrClient,(socklen_t*)&len);
			if(INVALID_SOCK == clientfd)
			{
				iRet = -7;	//accpet failed
				break;
			}

			
		}
		
	}while(0);
	
	return iRet;
}


