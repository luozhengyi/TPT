#include<TPT/msgManager.h>


int main(int argc, char* argv[])
{
	int iRet = 0;
	do
	{
		MsgManager msg_signin;
		msg_signin.ConstructMsg(E_SIGNIN,2,"luozhengyi","7412282");
		msg_signin.DeconstructMsg();

	}while(0);
	return iRet;
}

