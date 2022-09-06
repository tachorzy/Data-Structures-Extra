#include <iostream>
#include "BST.h"

int main() {
  BST *t = new BST(); 
  t->insert(t->root, 33);
  t->insert(t->root, 9);
  t->insert(t->root, 73);
  t->insert(t->root, 5);
  t->insert(t->root, 25);
  t->insert(t->root, 51);
  t->insert(t->root, 82);
  t->insert(t->root, 30);
  t->insert(t->root, 75);
  t->insert(t->root, 27);
  
  int menuInput, n1, n2;
  do{
    cout << "Enter two values form the given tree, and we'll find the lowest common ancestor of the two given nodes. To exit enter 0." << endl;
    cout << "\t\t  33\n\t\t/    \\\n\t   9      73\n\t  / \\     / \\\n\t 5  25   51  82\n\t\t  \\     /\n\t\t  30   75\n\t\t /\n\t\t27" << endl;
    if(cin >> n1)
      cout << "Node 1 is " << n1 << ", please enter a value for node 2" << endl;
    if(cin >> n2)
      cout << "searching for nodes" << endl;
    if(!t->search(t->root, n1) || !t->search(t->root, n2))
      cout << "One of the values you entered was not found in the tree, please try again" << endl;
    else
      cout << "The lowest common ancestor is: " << t->findLowestCommonAncestor(t->root, t->search(t->root, n1), t->search(t->root, n2)) << endl;
      cout << endl;
  }while(n1 != 0 || n2 != 0);
} 