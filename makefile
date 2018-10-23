cc = g++
obj1 = DBConn.o DBTester.o 
obj2 = login.o testLogin.o

TPTServer.out: $(obj1)
	$(cc) -o DBTester.out $(obj1) -lmysqlclient
testLogin.out:$(obj2) 
	$(cc) -g -o testLogin.out $(obj2)



DBTester.o: DBTester.cpp DBConn.h
	$(cc) -c DBTester.cpp 
DBConn.o: DBConn.cpp DBConn.h
	$(cc) -c DBConn.cpp 




login.o:login.cpp login.h
	$(cc) -g -c login.cpp

testLogin.o:testLogin.cpp login.h
	$(cc) -g -c testLogin.cpp




clean:
	rm -rf $(obj1) $(obj2)
