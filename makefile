cc = g++
obj1 = DBConn.o DBTester.o 
obj2 = login.o testLogin.o

TPTServer.out: $(obj1)
	$(cc) -o DBTester.out $(obj1) -lmysqlclient
testLogin.out:$(obj2) 
	$(cc) -g -o testLogin.out $(obj2)



DBTester.o: DBConn.h
DBConn.o: DBConn.h




login.o: login.h errorcode.h
testLogin.o: login.h


clean:
	rm -rf $(obj1) $(obj2)
