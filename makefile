CC=gcc
FLAGS=-g -Wall
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