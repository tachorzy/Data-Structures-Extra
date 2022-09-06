#include <iostream>
#include "BST.h"

int main() {
  BST t;
  t.insert(t.getRoot(), 10);
  t.insert(t.getRoot(), 8);
  t.insert(t.getRoot(), 15);
  t.insert(t.getRoot(), 2);
  t.insert(t.getRoot(), 7);
  t.insert(t.getRoot(), 20);
  t.insert(t.getRoot(), 1);
  t.insert(t.getRoot(), 6); 

  int menuInput, key;
  do{
    cout << "Press (1) To search from a BST.\nPress (0) to exit the menu" << endl;
    cin >> menuInput;
    if(menuInput == 1) {
      cout << "So you want to search a binary search tree? Enter a number, any number!" << endl;
      cin >> key;

      if(t.search(t.getRoot(), key))
        cout << key << " was found in the tree." << endl;
      else
        cout << key << " was not found in the tree" << endl;
    }

  }while(menuInput != 0);

} 