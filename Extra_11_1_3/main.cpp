#include <iostream>
#include "Tree.h"

int main() {
  Tree t;
  t.insert(t.getRoot(), 10);
  t.insert(t.getRoot(), 8);
  t.insert(t.getRoot(), 15);
  t.insert(t.getRoot(), 7);
  t.insert(t.getRoot(), 3);
  t.insert(t.getRoot(), 2);
  t.insert(t.getRoot(), 20);
  t.insert(t.getRoot(), 6); 

  int menuInput, key;
  do{
    cout << "Here's the drill, you're gonna enter a key, and we'll search for it in the binary search tree drawn below. If we find your key, we'll take that node and find it's depth. Ready?\n\tpress (1) to get started.\n\t press (0) to exit.\n\t\t 10\n\t\t/  \\\n\t   8    15\n\t  /\t\t  \\\n\t 7\t\t   20\n\t/\n   3\n  / \\\n 2   6" << endl;
    cin >> menuInput;
    if(menuInput == 1) {
      cout << "Enter a number of a node pictured above, then we'll find it's depth" << endl;
      cin >> key;
      Node* n = t.search(t.getRoot(), key);
    if(n != 0){
      int depth = t.depth(t.getRoot(), n, 0);
      cout << "the depth of the given node is " << depth << endl;
    }
    else 
      cout << "we could not find the given node in the tree." << endl;
    }
  }while(menuInput != 0);

} 