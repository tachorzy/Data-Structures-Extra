#include <iostream>
#include "BST.h"

using namespace std;

int main() {
  BST t;
  t.insert(t.getRoot(), 10);
  t.insert(t.getRoot(), 8);
  t.insert(t.getRoot(), 15);
  t.insert(t.getRoot(), 7);
  t.insert(t.getRoot(), 3);
  t.insert(t.getRoot(), 2);
  t.insert(t.getRoot(), 25);
  t.insert(t.getRoot(), 6); 
  cout << "for the given binary search tree\n\tpress (1) to get started.\n\t press (0) to exit.\n\t\t 10\n\t\t/  \\\n\t   8    15\n\t  /\t\t  \\\n\t 7\t\t   25\n\t/\n   3\n  / \\\n 2   6" << endl;
  cout << "max is: " << t.getMax(t.getRoot()) << endl;

} 