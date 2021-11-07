#include <iostream>
#include <string>
#include <cctype>
#include "bfs.h"

using namespace std;

int main(){
  string maze = "";
  string line;
  int size;
  while(getline(cin, line)){
    maze += line;
    size = line.length();
  }
  bfs b (maze, size);
  b.BFS(0);
  b.printPath();
  return 0;
}
