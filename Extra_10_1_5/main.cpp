#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
//Finding a palindrome using a stack and a queue.
bool ispalindrome(Stack s, Queue q){
  if(q.isempty() && s.isempty()) //base cause
    return true;

  else if(q.getSize() != s.getSize())
    return false;
  
  if(s.getTop()->l == q.getFront()->data) {
      s.pop();
      q.deQueue();
      return ispalindrome(s, q);
  } else
    return false;
}

int main() {
  char userInput;
  int menuInput;
  Stack mystack;
  Queue myqueue;

do{
  cout << "Hi, welcome to our menu... we're a little underbudget with the GUI but that's okay!\nToday we're gonna find a palindrome using a stack and a queue. Press:\n\t(1) to push into the stack \n\t(2) to enqueue into the queue\n\t(3) to check if the word you entered is a palindrome.\n\t(0) to exit once you're bored." << endl;
  cin >> menuInput;
  switch(menuInput) {
    case(1):
      cout << "Enter a char you want to add to the stack" << endl;
      cin >> userInput;
      mystack.push(userInput);
      break;
    case(2):
      cout << "Enter a char you want to add to the queue" << endl;
      cin >> userInput;
      myqueue.enQueue(userInput);
      break;
    case(3):
      if(ispalindrome(mystack, myqueue))
        cout << "THIS IS A PALINDROME!" << endl;
      else if(!ispalindrome(mystack, myqueue))
        cout << "THIS IS NOT A PALINDROME!" << endl;
      break;
  }
}while(menuInput != 0);
}