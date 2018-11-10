#ifndef __MSGMANAGER_H__
#define __MSGMANAGER_H__


enum msgtype{
	E_INIT = 0,
	E_SIGNIN,
	E_SIGNUP,
	E_LOGIN,
	E_LOGOUT,
	E_MSG,
	E_INVAILD

};

class MsgManager
{
#define MEM_LEN 1024
union un_msg{
	char memory[MEM_LEN];
	struct {
		msgtype type;		//message type
		unsigned char paramnum;	//parameter num
		unsigned char msglen;	//message len
	}head;
};
public:
	MsgManager();
	virtual ~MsgManager();
	
public:
	unsigned char GetMsgLen();

	msgtype GetMsgType();

	unsigned char GetParamNum();

public:
	bool ConstructMsg(msgtype type,unsigned char paramnum,...);

	bool DeconstructMsg();

	bool VerifyMsg();



private:
	un_msg msg;

};


#endif  //__MSGMANAGER_H__
