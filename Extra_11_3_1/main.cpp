/* Simple Graph and BFS implementation using STL classes
*/

#include <iostream>
#include "Graph.h"
int main() {
    cout << "Breadth First Search of Given graph:\n(0) 🡢 (1)\n 🡣\t   🡣\n(2) 🡢 (3) 🡢 (4)\n" << endl;

    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(0, 2);
    g.addEdge(2, 3);

    cout << "BFS traversal: ";
    g.BFS(0);
 
  cout << endl;

} 