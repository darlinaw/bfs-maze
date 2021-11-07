#include <iostream>
#include <string>
#include <climits>
#include <queue>
#include <cctype>
#include "bfs.h"

using namespace std;

bfs::bfs(string m, int n) : size(n), maze(m){
  color = new int[size*size];
  distance = new int[size*size];
  parent = new int[size*size];
  for(int i = 0; i < size*size; i++){
    color[i] = 0;
    distance[i] = INT_MAX;
    parent[i] = −1;
  }
}

bfs::~bfs(){
  delete[] color; color = 0;
  delete[] distance; distance = 0;
  delete[] parent; parent = 0;
}

int bfs::hexToInt(char c){
  if(c >= 65){
    return toupper(c) − 65 + 10;
  }
  else{
    int s = c;
    return c − 48;
  }
}

