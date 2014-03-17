CC=clang++
CFLAGS=--std=c++11 -g -Wall -Wfatal-errors

all: SevenBridges Board.o Tile.o Location.o

SevenBridges: SevenBridges.cpp Board.o Tile.o Location.o
	$(CC) $(CFLAGS) SevenBridges.cpp Board.o Tile.o Location.o -o SevenBridges

Board.o: Board.h Board.cpp
	$(CC) $(CFLAGS) -c Board.cpp -o Board.o

Tile.o: Tile.h Tile.cpp
	$(CC) $(CFLAGS) -c Tile.cpp -o Tile.o

Location.o: Location.h Location.cpp
	$(CC) $(CFLAGS) -c Location.cpp -o Location.o

.PHONY: clean

clean:
	rm SevenBridges *.o
