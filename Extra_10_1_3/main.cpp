#include <iostream>
#include <string>
#include "stack.h"
//converting a string in infix expression to a postfix expression

using namespace std;

int priority(char x) {
  if(x=='^')
    return 3;
  if(x =='/' || x=='*')
    return 2;
  if(x=='-' || x=='+')
    return 1;
  return -1; //return -1 if it isnt a valid char.
}



int main() {
  string sent;
  cout << "enter an infix expression e.g. a+b-c/d, please note that parentheses aren't accounted for in this program." << endl;
  cin >> sent;
  stack s = stack(sent.length());
  string output;

  for(int i = 0; i < sent.length(); i++) {
    if (isdigit(sent[i])){ 
      output += sent[i];
    }
    else if (s.isempty() || priority(sent[i]) > priority (s.peek())) {
      s.push(sent[i]);
      cout << "the size is: " << s.getSize() << endl;
      cout << "the top is: " << s.peek() << endl;
    }
    else if (priority(sent[i]) <= priority(s.peek())) {
      cout << "entered 2nd branch" <<endl;
      output += s.peek();
      s.pop();
      s.push(sent[i]);
    }
  }
  output += s.peek();
  cout << output << endl;
}