#include<iostream>
#include<cstring>

enum msgtype{
	E_LOGIN,
	E_LOGOUT,
	E_MSG,
	E_SIGNIN,
	E_SIGNUP

};

struct msg{
	msgtype type;
	unsigned char paramnum;
	char memory[1024];
	msg(){};
};

void fun()
{
#if defined(__linux__)
	std::cout<<"Linux"<<std::endl;
#elif defined(_WIN32)
	std::cout<<"windows"<<std::endl;
#endif
	
}

int main(int argc, char* argv[])
{
	int iRet = 0;

	msg message;
	message.type = E_SIGNIN;

	memcpy(message.memory,"haseef414",sizeof("haseef414")+1);

	fun();

	return iRet;
}

