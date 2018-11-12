#ifndef __ERRORCODE_H__
#define __ERRORCODE_H__

enum ErrCode
{
	EC_NULL_PTR      = -1,  //null pointer
	EC_NULL_FILE_PTR = -2,  //null file pointer
	EC_NULL_PARA_PTR = -3,  //null parameter pointer
	EC_PARAM_ERROR   = -4,  //parameter error

	//socket related
	EC_INVALID_FD    = -30,	//invalid fd
	EC_BIND_FAILED   = -31,	//bind failed
	EC_LISTEN_FAILED = -32,	//listen failed
	EC_ACCEPT_FAILED = -32,	// accept failed

	

};

//extern enum ErrCode  errcode;

#endif  //__ERRORCODE_H__
