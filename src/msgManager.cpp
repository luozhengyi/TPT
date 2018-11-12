#include<TPT/msgManager.h>
#include<iostream>
#include<cstdarg>
#include<cstdio>
#include<cstdlib>
#include<cstring>


MsgManager::MsgManager()
{
}




MsgManager::~MsgManager()
{
}



unsigned char MsgManager::GetMsgLen()
{
	return msg.head.msglen;
}

msgtype MsgManager::GetMsgType()
{
	return msg.head.type;
}

unsigned char MsgManager::GetParamNum()
{
	return msg.head.paramnum;
}

bool MsgManager::ConstructMsg(msgtype type, unsigned char paramnum,...)
{
	bool bRet = false;
	do{

		if(type>=E_INVAILD || type<E_INIT)
			break;

		memset(msg.memory,0,MEM_LEN);
		msg.head.type = type;
		msg.head.paramnum = paramnum;
		msg.head.msglen = sizeof(msg.head);
		
		bool bflag = true;
		va_list arg;
		va_start(arg,paramnum);
		char* pch = NULL;
		unsigned char paramlen = 0;
		char* pParamInfo = msg.memory + msg.head.msglen;  
		for(int idx = 0; idx < paramnum; ++idx)
		{
			pParamInfo += paramlen;

			pch = va_arg(arg,char*);
			paramlen = strlen(pch) + 1;

			msg.head.msglen += paramlen;
			if(msg.head.msglen > MEM_LEN)
			{
				bflag = false;
				break;
			}
			strncpy(pParamInfo,pch,paramlen -1);
		}
		va_end(arg);
		if(bflag)
			bRet = true;
	}while(0);
	
	return bRet;	

}



bool MsgManager::DeconstructMsg()
{
	bool bRet = false;
	do
	{
		if(msg.head.type <= E_INIT ||  msg.head.type>=E_INVAILD)
			break;
		char* pParamInfo = msg.memory + sizeof(msg.head); 
		unsigned char paramlen = 0;
		for(int idx =0; idx < msg.head.paramnum; ++idx)
		{
			pParamInfo += paramlen;
			std::cout<<pParamInfo<<std::endl;

			paramlen = strlen(pParamInfo) + 1;
		}
		bRet = true;
	}while(0);
	return bRet;
}


bool MsgManager::VerifyMsg()
{
	bool bRet  = false;
	do
	{
	}while(0);

	return bRet;
}




