CC  = gcc
CXX = g++

SRC_DIR = ./src
INC_DIR = ./include
TEST_DIR = ./test
BIN_DIR = ./bin

obj1 = DBConn.o DBTester.o 

$(BIN_DIR)/TPTServer.out: $(obj1)
	$(CXX) -o $(BIN_DIR)/DBTester.out $(obj1) -lmysqlclient

DBTester.o: $(INC_DIR)/DBConn.h
	$(CXX) -c  $(TEST_DIR)/DBTester.cpp
DBConn.o: $(INC_DIR)/DBConn.h
	$(CXX) -c  $(SRC_DIR)/DBConn.cpp 


clean:
	rm -rf $(obj1) 
