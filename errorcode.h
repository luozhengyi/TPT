#ifndef __ERRORCODE_H__
#define __ERRORCODE_H__

enum ErrCode
{
	NULL_PTR      = -1,  //null pointer
	NULL_FILE_PTR = -2,  //null file pointer
	NULL_PARA_PTR = -3,  //null parameter pointer
	PARAM_ERROR   = -4,  //parameter error

	//socket related
	INVALID_FD    = -30,	//invalid fd
	BIND_FAILED   = -31,	//bind failed
	LISTEN_FAILED = -32,	//listen failed

	

};

#endif  //__ERRORCODE_H__
