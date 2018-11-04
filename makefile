CC  = gcc
CXX = g++

SRC_DIR = ./src
INC_DIR = ./include
TEST_DIR = ./test
BIN_DIR = ./bin


ALL: $(BIN_DIR)/DBTester.out $(BIN_DIR)/testLogin.out
.PHONY: ALL

OBJ1 = DBConn.o DBTester.o 
OBJ2 = login.o  testLogin.o

# generate DBTester.out
$(BIN_DIR)/DBTester.out: $(OBJ1)
	$(CXX) -o $(BIN_DIR)/DBTester.out $(OBJ1) -lmysqlclient

DBTester.o: $(INC_DIR)/DBConn.h
	$(CXX) -c  $(TEST_DIR)/DBTester.cpp
DBConn.o: $(INC_DIR)/DBConn.h
	$(CXX) -c  $(SRC_DIR)/DBConn.cpp 


# generate testLogin.out
$(BIN_DIR)/testLogin.out: $(OBJ2)
	$(CXX) -o $(BIN_DIR)/testLogin.out $(OBJ2)

login.o: $(INC_DIR)/login.h
	$(CXX) -c $(SRC_DIR)/login.cpp
testLogin.o: $(INC_DIR)/login.h
	$(CXX) -c $(TEST_DIR)/testLogin.cpp

.PHONY: clean
clean:
	rm -rf $(OBJ1) $(OBJ2) 
	
