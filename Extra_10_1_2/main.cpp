#include <iostream>
#include "stack.h"

using namespace std;

int main() {

int menuInput;
char userInput;
stack a(10);

do {
cout << "Welcome to Extra Stacked Extras: Stack edition, this is a program of a stack implementation of a dynamic array. Before you get stackin', do keep in mind that the stack has a limit of 10 stacks you can stack into the stack.\n1. push into the stack\n2. pop from the stack\n3. pop everything from the stack\n4. print the stack\n5. peek at the top of the stack\n0. to exit Extra Stacked Extras: Stack edition." << endl;
cin >> menuInput;
switch(menuInput) {
  case(1):
    cout << "Enter a char you want to add to the stack" << endl;
    cin >> userInput;
    a.push(userInput);
    break;
  case(2):
    a.pop();
    break;
  case(3):
    a.popAll();
    break;
  case(4):
    cout << "NOW PRINTING THE STACK: " << endl;
    a.print(a.getSize());
    break;
  case(5):
    a.peek();
    break;
  }
}while(menuInput != 0);

cout << "see you in our sequel Extra Queued Extras: Queue edition w/ the LinkedList Expansion pack (extra credit not included)." << endl;

}