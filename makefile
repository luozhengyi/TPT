CC  = gcc
CXX = g++

SRC_DIR = ./src
INC_DIR = ./include
TEST_DIR = ./test
BIN_DIR = ./bin


ALL: $(BIN_DIR)/DBTester.out $(BIN_DIR)/server.out $(BIN_DIR)/client.out
.PHONY: ALL

OBJ1 = DBConn.o DBTester.o 
OBJ2 = login.o  server.o
OBJ3 = client.o

# generate DBTester.out
$(BIN_DIR)/DBTester.out: $(OBJ1)
	$(CXX) -o $(BIN_DIR)/DBTester.out $(OBJ1) -lmysqlclient

DBTester.o: $(TEST_DIR)/DBTester.cpp $(INC_DIR)/DBConn.h
	$(CXX) -c  $(TEST_DIR)/DBTester.cpp
DBConn.o:   $(SRC_DIR)/DBConn.cpp    $(INC_DIR)/DBConn.h
	$(CXX) -c  $(SRC_DIR)/DBConn.cpp 


# generate server.out
$(BIN_DIR)/server.out: $(OBJ2)
	$(CXX) -o $(BIN_DIR)/server.out $(OBJ2)

login.o:  $(SRC_DIR)/login.cpp   $(INC_DIR)/login.h
	$(CXX) -c $(SRC_DIR)/login.cpp
server.o: $(TEST_DIR)/server.cpp $(INC_DIR)/login.h
	$(CXX) -c $(TEST_DIR)/server.cpp


# generate client.out
$(BIN_DIR)/client.out: $(OBJ3)
	$(CXX) -o $@ $<

client.o: $(TEST_DIR)/client.cpp
	$(CXX) -c $<



.PHONY: clean
clean:
	rm -rf $(OBJ1) $(OBJ2) $(OBJ3)
	
