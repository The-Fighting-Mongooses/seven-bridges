CC=clang++
CFLAGS=--std=c++11 -g -Wall -Wfatal-errors

all: SevenBridges GameEngine.o Board.o Tile.o Location.o

SevenBridges: SevenBridges.cpp GameEngine.o Board.o Tile.o Location.o Scanner.o UserInterface.o Obstacle.o
	$(CC) $(CFLAGS) SevenBridges.cpp Scanner.o UserInterface.o GameEngine.o Board.o Tile.o Location.o Obstacle.o -o SevenBridges

GameEngine.o: GameEngine.h GameEngine.cpp Scanner.h UserInterface.h Board.h
	$(CC) $(CFLAGS) -c GameEngine.cpp -o GameEngine.o

Board.o: Board.h Board.cpp Location.h Tile.h
	$(CC) $(CFLAGS) -c Board.cpp -o Board.o

Tile.o: Tile.h Tile.cpp Location.h
	$(CC) $(CFLAGS) -c Tile.cpp -o Tile.o

Obstacle.o: Obstacle.h Obstacle.cpp Location.h
	$(CC) $(CFLAGS) -c Obstacle.cpp -o Obstacle.o

Location.o: Location.h Location.cpp
	$(CC) $(CFLAGS) -c Location.cpp -o Location.o

Scanner.o: Scanner.cpp Scanner.h Location.h Board.h Tile.h Obstacle.h
	$(CC) $(CFLAGS) -c Scanner.cpp

UserInterface.o: UserInterface.cpp UserInterface.h Board.h
	$(CC) $(CFLAGS) -c UserInterface.cpp


.PHONY: clean

clean:
	rm SevenBridges *.o
