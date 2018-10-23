cc = g++
obj = DBConn.o DBTester.o 

TPTServer.out: $(obj)
	$(cc) -o DBTester.out DBTester.o DBConn.o -lmysqlclient
DBTester.o: DBTester.cpp DBConn.h
	$(cc) -c DBTester.cpp 
DBConn.o: DBConn.cpp DBConn.h
	$(cc) -c DBConn.cpp 

clean:
	rm -rf $(obj)
