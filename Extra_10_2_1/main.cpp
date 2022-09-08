#include <iostream>
#include "stack.h"
#include "expNotation.h"

int main() {
  expNotation exp; 
  int userInput;
  do{
    cout << "Main Menu:\nThis is a program that allows you to convert between infix and postfix expressions, aswell evaluate postfix expressions. All userinputs must be operators and operands. Parentheses are not supported, and all operands must be single digits. For evaluating postfix expressions, all inputs must be integers.\n\t(1) To convert Infix to Postfix.\n\t(2) To convert Postfix to Infix.\n\t(3) To evaluate a Postfix expression.\n\t(0) Exit." << endl;
    cin >> userInput;

    string userExp;
    switch(userInput){
      case 1:
        cout << "Please enter an expression in infix notation" << endl;
        cin >> userExp;
        exp.infixToPostfix(userExp);
        break;
      case 2:
        cout << "Please enter an expression in postfix notation" << endl;
        cin >> userExp;
        exp.postfixToInfix(userExp);
        break;
      case 3:
        cout << "Please enter an expression in postfix notation. (All operands must be integers!)" << endl;
        cin >> userExp;
        exp.evalPostfix(userExp);
        break;
    }
  }while(userInput != 0);

}