p8: main.o bfs.o
g++ −o p8 −std=c++11 main.o bfs.o
main.o: main.cpp bfs.h
g++ −c −std=c++11 main.cpp
bfs.o: bfs.cpp bfs.h
g++ −c −std=c++11 bfs.cpp
clean:
rm −f p8 *.o *.~
