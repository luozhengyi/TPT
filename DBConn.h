#ifndef __DBCONN_H__
#define __DBCONN_H__

#include <mysql/mysql.h>

#define nullptr 0 
typedef int (*parsecb)(MYSQL_RES*);
class DBConn
{
public:
	DBConn();
	virtual ~DBConn();

public:
	void Init();
	int connect(const char* const host,const short port,
		    const char* const user,const char* const pwd,
		    const char* const db);

public:
	int query(parsecb parse,const char* const sqlCmd);
	

private:
	const char* host;	//db address
	short port;	        //db port
	const char* user;
	const char* pwd;
	const char* db;		//database name
	MYSQL* conn;
	bool bConn;		//true: conn sucess; false:conn faid
};




#endif  //__DBCONN_H__
