#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph{
private:
  int V;
  vector<list<int>> adj;
public:
  Graph(int _v){
    V = _v;
    adj.resize(V);
  }

  void addEdge(int src, int dest){
    adj[src].push_back(dest);
  }

  void BFS(int s){
    vector<bool> visited(V);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while(!q.empty()){
      s = q.front();
      cout << s << " ";
      q.pop();
      for(auto i : adj[s]) {
        if(!visited[i]){
          visited[i] = true;
          q.push(i);
        }
      }
    }
  }
};