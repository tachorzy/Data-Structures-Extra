#include <iostream>
#include "mystack.h"

using namespace std;

int main() {
  mystack s;
  char vtopop;
  //Search for duplicates with a boolean array, which has a time complexity of O(n), instead of searching the stack with a time complexity of O(n^2).
  bool test[20];
  int c = 0;
  while(c < 20) {
    char t = rand()%26 + 97; //range of the 26 lower case ASCII values
    if (test[int(t)-97] != 1) { //checks for duplicates
      s.push(t);
      c++;
      test[int(t)-97] = 1;
    }
  }
  string userInput = "";

  do{
    cout << "Printing random chars from the stack: (press ` to quit)" << endl;
    s.print();
    cout << endl;
    cout << "type 'pop' to keep poppin' nodes from the stack:" << endl;
    cin >> userInput;
    s.pop(vtopop);
    cout << "we just deleted " << vtopop << endl;
  }while(userInput == "pop" && s.isempty() == false);

  if(s.isempty())
    cout << "welp... you've gotten nothing to pop. Cya" << endl;
  else if(userInput != "pop")
    cout << "next time type 'pop'" << endl;
}