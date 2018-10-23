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
	/*
	 *@fun:  connect
	 *@desc: connect to database
	 *@para:
	 *@ret:  0:success others:error code
	 */
	int connect(const char* const host,const short port,
		    const char* const user,const char* const pwd,
		    const char* const db);

public:
	/*
	 *@fun:  query
	 *@desc: query to database
	 *@para: parsecb:query result parse callback fun; sqlCmd:sql commad
	 *@ret:  0:success others:error code
	 */
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
