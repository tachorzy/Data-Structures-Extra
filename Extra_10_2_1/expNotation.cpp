/*program to allow you to switch between expression notations, along with other related features*/
#include <string>
#include "expNotation.h"
#include "stack.h"
#include <cmath>

bool expNotation::isOperator(char c){
  if(c == '^' || c == '/' || c == '*' || c == '+' || c == '-')
    return true;
  return false;
}

int expNotation::priority(char c){
  if(c == '^')
    return 3;
  if(c == '*' || c == '/')
    return 2;
  else if(c == '+' || c == '-')
    return 1;
}

void expNotation::infixToPostfix(string str){
  stack <char> reserve(str.length());
  string postfix;
  for(int i = 0; i < str.length(); i++) {
    if(isalnum(str[i]))
      postfix += str[i];
    else if(isOperator(str[i])){
      if (reserve.isempty() || priority(str[i]) > priority (reserve.peek())) {
        reserve.push(str[i]);
      }
      else{
        while (!reserve.isempty() && priority(str[i]) <= priority(reserve.peek())) {
          postfix += reserve.peek();
          reserve.pop();
        }
        reserve.push(str[i]);
      }
    }
  }
  while(!reserve.isempty()){//flushes the stack
    postfix += reserve.peek();
    reserve.pop();
  }
  cout << "postfix:" << postfix << endl;
}

void expNotation::postfixToInfix(string str) {
  stack <string> reserve(str.length());
  string infix;
  for(int i = 0; i < str.length(); i++) {
    if(isalnum(str[i])){
      string op(1,str[i]);
      reserve.push(op);
    }

    else if(isOperator(str[i])) {
      string operand2 = reserve.peek(); //FILO
      reserve.pop();
      string operand1 = reserve.peek();
      reserve.pop();
      reserve.push(operand1 + str[i] + operand2);
    }
  }
  infix = reserve.peek();
  cout << "infix:" << infix << endl;
} 

void expNotation::evalPostfix(string str){
  stack <int> reserve(str.length());
  int result = 0;
  for(int i = 0; i < str.length(); i++){
    if(isdigit(str[i])){
      int op = (int)str[i] - 48; //
      reserve.push(op);
    }
    else if(isOperator(str[i])){
      int operand2 = reserve.peek();
      reserve.pop();
      int operand1 = reserve.peek();
      reserve.pop();

      switch(str[i]){
        case '^':
          reserve.push(pow(operand1,operand2));
          break;
        case '/':
          reserve.push(operand1/operand2);
          break;
        case '*':
          reserve.push(operand1*operand2);
          break;
        case '+':
          reserve.push(operand1+operand2);
          break;
        case '-':
          reserve.push(operand1-operand2);
          break;
      }
    }
  }
  result = reserve.peek();
  cout << "evaluation of postfix expression: " << result << endl;
}

