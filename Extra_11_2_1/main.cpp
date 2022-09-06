/*Hi, in this extra I wrote a recursive function that inverts a Binary Tree. This means that each node gets it's two child swapped.*/
#include <iostream>
#include "BST.h"

int main() {
  BST b;
  b.insert(b.getRoot(), 8);
  b.insert(b.getRoot(), 3);
  b.insert(b.getRoot(), 6);
  b.insert(b.getRoot(), 10);
  b.insert(b.getRoot(), 12);
  b.print(b.getRoot());
  b.invert(b.getRoot());
  b.print(b.getRoot()); 
}