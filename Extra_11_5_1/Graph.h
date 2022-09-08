#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include "AirportData.h"

#define INFINITY 2147483647

using namespace std;

class Graph{
  private:
    int v;
    list<pair<int, int>> *adj;
  public:
    Graph(int _v){
      v = _v;
      adj = new list<pair<int, int>>[v];
    }
    void addEdge(int a, int b, int weight){
       adj[a].push_back(make_pair(b, weight));
       adj[b].push_back(make_pair(a, weight));
    }
    
    int shortestPath(int source, int dest, map<int, Airport> airports){
      set<pair<int,int>> g_set;      
      vector<int> distances(v, INFINITY);

      distances[source] = 0;
      g_set.insert(make_pair(0, source));
      cout << "Connections avaliable through: " << endl;
      while(!g_set.empty()){
        pair<int, int> temp = *(g_set.begin());
        g_set.erase(g_set.begin());
        int v1 = temp.second;
        
        bool layover = false;
        Airport connection("","","",0);

        for(auto it = adj[v1].begin(); it != adj[v1].end(); it++){
          int v2 = (*it).first;
          int w = (*it).second;

          if(distances[v2] > distances[v1] + w){
            if(distances[v2] != INFINITY)
              g_set.erase(g_set.find(make_pair(distances[v2], v2)));
            else //if the distance between source and destination is INF, there's a layover somewhere.
              layover = true;

            if(layover && connection.code != airports.find(v1)->second.code && airports.find(v1)->second.code != airports.find(source)->second.code && airports.find(v1)->second.code != airports.find(dest)->second.code) {
              cout << airports.find(v1)->second.name << " (" << airports.find(v1)->second.code << ")" <<", " << airports.find(v1)->second.location << endl; 
              connection = airports.find(v1)->second; //updating the connection.
            }

            distances[v2] = distances[v1] + w;
            g_set.insert(make_pair(distances[v2], v2));
          }
        }
      }
    cout << "Shortest path between " << airports.find(source)->second.code << " and " << airports.find(dest)->second.code << ": ";
    return distances[dest];
  }

  void build(){ //builds all of the airport connections, this could be done in main but I don't want to cram it too much lol
    //each vertex is an airport and each edge is weighted by the miles between the two airports.
    //Houston connections
    this->addEdge(0, 1, 5012);
    this->addEdge(0, 2, 8168);
    this->addEdge(0, 3, 1280);
    this->addEdge(0, 4, 763);
    this->addEdge(0, 6, 5232);
    this->addEdge(0, 8, 4825);
    this->addEdge(0, 7, 1417);
    this->addEdge(0, 9, 1379);
    this->addEdge(0, 11, 6663);
    this->addEdge(0, 17, 6371);
    this->addEdge(0, 22, 4667);
    //Amsterdam connections
    this->addEdge(1, 2, 3215);
    this->addEdge(1, 7, 3643); 
    this->addEdge(1, 8, 231);
    this->addEdge(1, 12, 5549);
    this->addEdge(1, 15, 6535);
    this->addEdge(1, 17, 1373);
    this->addEdge(1, 20, 806); 
    this->addEdge(1, 20, 248);
    this->addEdge(1, 21, 771);
    this->addEdge(1, 21, 771);
    //Dubai connections
    this->addEdge(2, 17, 1883);
    this->addEdge(2, 8, 3420);
    this->addEdge(2, 7, 6849);
    //Toronto connections
    this->addEdge(3, 1, 3733);
    this->addEdge(3, 5, 5746);
    this->addEdge(3, 6, 3952);
    this->addEdge(3, 8, 3556);
    this->addEdge(3, 12, 7107);
    //Mexico City connections
    this->addEdge(4, 22, 4085);
    this->addEdge(4, 23, 4758);
    //Heathrow connections
    this->addEdge(8, 5, 2197);
    this->addEdge(8, 7, 3451);
    this->addEdge(8, 9, 5456);
    this->addEdge(8, 14, 5958);
    this->addEdge(8, 15, 6765);
    this->addEdge(8, 16, 4191);
    this->addEdge(8, 17, 1550);
    this->addEdge(8, 20, 216);
    this->addEdge(8, 21, 713);
    //Istanbul connections
    this->addEdge(17,18, 1486);
    this->addEdge(17, 5, 782);
    this->addEdge(17, 19, 855);
  }

};