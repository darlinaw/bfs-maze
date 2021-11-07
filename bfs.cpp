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

vector<int> bfs::adjList(int n){
  vector<int> adjList;
  char c = maze[n];
  int s = hexToInt(c);
  if(s % 2 == 0 && n % size != (size − 1))
    adjList.push_back(n+1);
  if((s <= 3) || (s >= 8 && s <= 11) && n % size != 0)
    adjList.push_back(n−1);
  if(s <= 7 && (n − 1) >= 0)
    adjList.push_back(n − size);
  if((s % 4 == 0 || s % 4 == 1) && (n + 1) < size*size)
    adjList.push_back(n+size);
  return adjList;
}

void bfs::BFS(int s){
  color[s] = 1;
  distance[s] = 0;
  parent[s] = −1;
  queue<int> Q;
  Q.push(s);
  
  while(!Q.empty()){
    int t = Q.front();
    vector<int> adj = adjList(t);

    for(int j = 0; j < adj.size(); j++){
      int v = adj[j];

     if(color[v] == 0){
        color[v] = 1;
        distance[v] = distance[t] + 1;
        parent[v] = t;
        Q.push(v);
     }
    }
    Q.pop();
    color[t] = 2;
  }
}

void bfs::printPath(){
  vector<int> path;
  int i = size*size − 1;
  while(i >= 0){
    path.push_back(i);
    i = parent[i];
  }
  for(int j = path.size() − 1; j >= 0; j−−)
    cout << "(" << path[j]%size << ", " << path[j]/size << ")" << endl;
}
