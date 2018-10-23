#include <iostream>
#include <mysql/mysql.h>
#include "DBConn.h"
#include "errorcode.h"

int parse(MYSQL_RES* sqlRes)
{
	int iRet = 0;
	do
	{
		if(sqlRes == nullptr)
		{
			iRet = NULL_PARA_PTR;
			break;
		}
		my_ulonglong iRows = mysql_num_rows(sqlRes);
		unsigned int iFields = mysql_num_fields(sqlRes);
		std::cout<<"result has "<<iRows<<" rows."<<std::endl;
		std::cout<<"record has "<<iFields<<" fields."<<std::endl;
		
		MYSQL_ROW sqlRow;
		while(sqlRow = mysql_fetch_row(sqlRes))
		{
			for(unsigned int i=0;i<iFields;++i)
				std::cout<<sqlRow[i]<<"\t\t"<<std::endl;
			std::cout<<std::endl;
		}
		mysql_free_result(sqlRes);
	       	
	}while(0);

	return iRet;
}

int main(int argc,char* argv[])
{
	const char* host = "127.0.0.1";
	const short port = 3306;
	const char* user = "root";
	const char* pwd  = "7412282";
	const char* db   = "net";
	const char* const sqlCmd = "SELECT * FROM user";

	DBConn dbObj;
	int res = dbObj.connect(host,port,user,pwd,db);
	res = dbObj.query(parse,sqlCmd);

	return 0;
}
