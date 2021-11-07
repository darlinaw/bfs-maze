#ifndef BFS_H
#define BFS_H
#include <string>
#include <vector>
#include <queue>

class bfs {
  public:
  
  bfs(std::string, int); // constructor, sets initial values
  ~bfs(); // destructor
  void BFS(int); // does BFS on the maze
  void printPath(); // prints shortest path
  
  private:
  
  const int size;
  const std::string maze; // string that holds maze
  int* color; // 0 is white, 1 is gray, 2 is black
  int* distance; // init to INT_MAX
  int* parent; // init to −1
  std::vector<int> adjList(int); // adjList function that pushes back adj nodes
  int hexToInt(char); // converts to char hex to int

};

#endif
