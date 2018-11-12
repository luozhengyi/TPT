#include <iostream>
#include <TPT/DBConn.h>
#include <TPT/errorcode.h>

DBConn::DBConn():host(nullptr),port(0),user(nullptr),pwd(nullptr),
		 db(nullptr),conn(nullptr),bConn(false)
{

}

DBConn::~DBConn()
{
	if(conn != nullptr)
		mysql_close(conn);
}

void DBConn::Init()
{
	host = nullptr;
	port = 0;
	user = nullptr;
	pwd  = nullptr;
	db   = nullptr;
	if(conn != nullptr)
		mysql_close(conn);
	conn = nullptr;
	bConn= false;
}

int DBConn::connect(const char* const host, const short port,
		    const char* const user, const char* const pwd,
	       	    const char* const db)
{
	int iRet = 0;
	do
	{

		if(host == nullptr || user == nullptr || pwd == nullptr ||
		   db == nullptr)
		{
			iRet = EC_NULL_PARA_PTR;
			break;
		}

		if(conn != nullptr)
		{
			mysql_close(conn);
			conn = nullptr;
		}
		conn = mysql_init(NULL);

		if(0 == mysql_real_connect(conn,host,user,pwd,db,port,"TCPIP",0))
		{
			std::cout<<mysql_error(conn)<<std::endl;
			std::cout<<mysql_errno(conn)<<std::endl;	
			break;
		}
		mysql_query(conn,"SET NAMES GBK");	//set db table character sets
		bConn = true;
	}while(0);
	return iRet;
}


int DBConn::query(parsecb parse,const char* const sqlCmd)
{
	int iRet = 0;
	do
	{
		if(bConn == false)
			break;
		if(parse == nullptr || sqlCmd == nullptr)
		{
			iRet = EC_NULL_PARA_PTR;
			break;
		}
		int res = mysql_query(conn,sqlCmd);
		if(res == 0)
		{
			MYSQL_RES* sqlRes = nullptr;
			sqlRes = mysql_store_result(conn);
			iRet = parse(sqlRes);
		}
	}while(0);


	return iRet;
}












