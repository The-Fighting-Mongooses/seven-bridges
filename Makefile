all: Main

Main: main.cpp location.o tile.o
	clang++  --std=c++11 -g -Wall main.cpp location.o tile.o -o Main

location.o: Location.cpp Location.h
	clang++ --std=c++11 -g -Wall Location.cpp -c -o location.o

tile.o: Tile.cpp Tile.h
	clang++ --std=c++11 -g -Wall Tile.cpp -c -o tile.o

.PHONY: clean

clean:
	rm Main *.o
