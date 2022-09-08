#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph{
private:
  int V;
  vector<list<int>> adj;
  vector<bool> visited;

public:
  Graph(int _v){
    V = _v;
    adj.resize(V);
    visited.resize(V);
  }

  void addEdge(int src, int dest){
    adj[src].push_back(dest);
  }

  void DFS(int s){
    visited[s] = true;

    cout << s << " ";

    for(auto i : adj[s]) {
      if(!visited[i]){
        visited[i] = true;
        DFS(i);
      }
    }
  }
};