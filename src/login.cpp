#include <TPT/login.h>
#include <unistd.h>	//close()
#include <strings.h>	//bzero()
#include <TPT/errorcode.h>
#include <TPT/errorcode.h>

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
		if(fd < 0)
		{
			iRet = EC_INVALID_FD;	//create socket fd failed
			break;
		}

		bzero(&addrSrv,sizeof(sockaddr_in));
		addrSrv.sin_family = AF_INET;
		addrSrv.sin_port = htons(port);
		addrSrv.sin_addr.s_addr = htonl(INADDR_ANY);
		
		if( bind(fd,(sockaddr*)&addrSrv,sizeof(sockaddr_in)) < 0)
		{//bind: @ret 0:success -1:failed
			iRet = EC_BIND_FAILED;	//bind failed
			break;
		}
		
		if(listen(fd,10) < 0)
		{//listen: @ret 0:success -1:failed
			iRet = EC_LISTEN_FAILED;	//listen setup failed
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
				iRet = EC_ACCEPT_FAILED;	//accept failed
				break;
			}

			
		}
		
	}while(0);
	
	return iRet;
}


