CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/node.o $(OBJ)/graph.o $(OBJ)/main.o 
HDRS =$(INC)/node.hpp $(INC)/graph.hpp
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

all: $(BIN)/tp2.out
	
$(BIN)/tp2.out: $(OBJS)
	$(CC) -o $(BIN)/tp2.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp   
	
$(OBJ)/node.o: $(HDRS) $(SRC)/node.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/node.o $(SRC)/node.cpp

$(OBJ)/graph.o: $(HDRS) $(SRC)/graph.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/graph.o $(SRC)/graph.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out