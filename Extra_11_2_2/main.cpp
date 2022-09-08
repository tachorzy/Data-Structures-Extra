/* In this extra, I made a Binary Treee that inserts in level order (bfs), wrote a function to count the sum of all the Tree's leaves. 
*/

#include <iostream>
#include "Tree.h"

int main() {
  Tree t;
  int menuInput;
  int n;

  t.insert(1); 
  t.insert(2); 
  t.insert(3); 
  t.insert(4); 
  t.insert(5);

  t.printlevelorder(t.root);
  cout << "leaves: ";
  t.printLeaves(t.root);
  cout << endl;
  cout << "height: " << t.height(t.root) << endl;
  cout << "sum of the leaves: " << t.sumOfLeaves(t.root, 0) << endl;
} 