CC=g++
FLAGS=-std=c++17 -g -Wall
LFLAGS=$(FLAGS) -lncurses
BINDIR=bin
BIN=$(BINDIR)/main
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

all:$(BIN)

$(BIN): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -lncurses -o $@

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(FLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/%.o: $(SRC)/%.cpp $(SRC)/%.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(BINDIR)/* $(OBJ)/*


test: Intel8080.o LinkedList.o
	$(CC) $(FLAGS) $(SRC)/test.cpp -o $(BINDIR)/test $(OBJ)/Intel8080.o $(OBJ)/LinkedList.o
	./bin/test

Intel8080.o: $(SRC)/components/cpu/Intel8080.cpp $(SRC)/components/cpu/Intel8080.h
	$(CC) $(FLAGS) -c $(SRC)/components/cpu/Intel8080.cpp -o $(OBJ)/Intel8080.o

LinkedList.o: $(SRC)/utils/LinkedList.cpp $(SRC)/utils/LinkedList.h
	$(CC) $(FLAGS) -c $(SRC)/utils/LinkedList.cpp -o $(OBJ)/LinkedList.o
