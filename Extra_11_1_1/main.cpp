#include <iostream>
#include "Tree.h"
int main() {
  Tree t;
  t.insert(t.getRoot(), 10);
  t.insert(t.getRoot(), 8);
  t.insert(t.getRoot(), 9);
  t.insert(t.getRoot(), 15);
  t.insert(t.getRoot(), 7);
  t.insert(t.getRoot(), 20);
  t.insert(t.getRoot(), 6); 
  t.insert(t.getRoot(), 5); 

  
   cout << "Given the following BST:\n\t\t 10\n\t\t/  \\\n\t   8    15\n\t  /\t\\\t  \\\n\t 7\t 9\t  20\n\t/\n   6\n  / \n 5" << endl;  
  cout << "PRINTED INORDER: ";
  t.printInorder(t.getRoot());
  cout << "PRINTED IN POSTORDER: ";
  t.printPostorder(t.getRoot());
  cout << "PRINTED IN PREORDER: ";
  t.printPreorder(t.getRoot());
  cout << "\n";
  cout << "\t~ 0 trees were hurt in the making of this extra." << endl;
} 