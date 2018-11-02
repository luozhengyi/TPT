#include <TPT/login.h>

int main(int argc,char* argv[])
{
	int iRet =0;
	login server;
	iRet = server.start();
	return iRet;
}
