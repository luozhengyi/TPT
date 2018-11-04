#include<unistd.h>  //close()
#include<strings.h> //bzero()
#include<netinet/in.h> //sockaddr_in
#include<sys/types.h> //socket data types
#include<sys/socket.h>	//socket api
#include<arpa/inet.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>

bool parseAddr(const char* const path, unsigned int& ip,unsigned short& port)
{
	bool bRet = false;
	std::fstream fs;

	do
	{
		if(path == NULL)
		{
			std::cout<<"invalid file path!"<<std::endl;
			break;
		}

		fs.open(path,std::ios::in);
		if(!fs)
		{
			std::cout<<"open file failed!"<<std::endl;
			break;
		}
		char ch_ip[16];
		char ch_port[10];
		
		bzero(ch_ip,sizeof(ch_ip));
		bzero(ch_port,sizeof(ch_port));

		fs.getline(ch_ip,sizeof(ch_ip)-1);
		fs.getline(ch_port,sizeof(ch_port)-1);
		
		if(inet_pton(AF_INET,ch_ip,&ip) != 1)
		{
			std::cout<<"get ip addr failed!"<<std::endl;
			break;
		}

		port = (short)atoi(ch_port);

		bRet = true;
	}while(0);
	fs.close();
	return bRet;
}




int main(int argc, char* argv[])
{
	int iRet = -1;
	int fd = -1;
	do
	{
		if(argc < 3)
		{
			std::cout<<"no enough args!"<<std::endl;
			break;
		}
		if((fd = socket(AF_INET,SOCK_STREAM,0))<0)
		{
			std::cout<<"create fd failed!"<<std::endl;
			break;	
		}
		sockaddr_in addrSrv;
		bzero(&addrSrv,sizeof(sockaddr_in));
		addrSrv.sin_family = AF_INET;
		parseAddr("addrlist",addrSrv.sin_addr.s_addr,addrSrv.sin_port); 



	}while(0);

	close(fd);
	return iRet;
}
