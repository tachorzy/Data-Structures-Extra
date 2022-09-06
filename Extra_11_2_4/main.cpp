/* In this extra, I'll be converting a BST to a min heap by using an inorder traversal of the tree and preorder traversal of a vectore in O(n) time.*/

#include <iostream>
#include "BST.h"
int main() {
  BST t;
  t.insert(t.getRoot(), 32);
  t.insert(t.getRoot(), 2);
  t.insert(t.getRoot(), 16);
  t.insert(t.getRoot(), 64);
  t.insert(t.getRoot(), 128);
  t.insert(t.getRoot(), 8);
  t.insert(t.getRoot(), 4);
  t.insert(t.getRoot(), 1);
  cout << "preorder traversal of the BST:" << endl;
  t.printPreorder(t.getRoot());
  cout << "preorder traversal of the min heap" << endl;
  t.toMinHeap(t.getRoot());
  t.printPreorder(t.getRoot());
} 