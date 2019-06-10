all: maze

maze: main.o cell.o maze.o
	g++ -std=c++14 main.o cell.o maze.o -o maze

main.o: main.cpp
	g++ -std=c++14 -c main.cpp

cell.o: cell.cpp
	g++ -std=c++14 -c cell.cpp

maze.o: maze.cpp
	g++ -std=c++14 -c maze.cpp

clean:
	rm -rf *.o maze