/*Full implementation of an AVL tree, with both insertion and deletion. I also added functions for level order printing and "level by level printing" All of which you can play with in the menu.*/

#include <iostream>
#include "AVL.h"

int main() {
  AVL* t = new AVL();

  int menuInput, userInput;
  do {
    cout << "AVL Tree:" << endl;
    t->printlevelorder(t->root);
    cout << "height: " << t->height(t->root)<< endl;
    cout << "Menu:\n\t(1) Add a key to the AVL Tree\n\t(2) Delete a key from the AVL Tree\n\t(0) Exit." << endl;
    cin >> menuInput;
    switch(menuInput){
      case 1:
        cout << "pick a number, any number, and we'll add it to our tree." << endl;
        cin >> userInput;
        t->insert(t->root, userInput);
        break;
      case 2:
        cout << "pick a number from the tree that you want to delete." << endl;
        cin >> userInput;
        t->deleteNode(t->root, userInput);
        break;
    }
  }while(menuInput != 0);
} 