//File labyrinth.maze

labyrinth: labyrinth.o maze.o
    c++ -o labyrinth labyrinth.o maze.o

labyrinth.o: labyrinth.cpp maze.h
    c++ -c labyrinth.cpp

maze.o: maze.cpp maze.h
    c++ -c maze.cpp

clean:
    run -f *.o *~ ./#*#

