#include <iostream>
#include <string>
#include <stack>

using namespace std;

//program to check for balanced parantheses in a given expression.
bool isbalanced(string exp){
  stack<char> st;
  for(int i = 0; i < exp.length(); i++){
    if(exp[i] == '(')
      st.push(exp[i]);

    if(st.empty())
      return false;
    if(exp[i] == ')')
      st.pop();
  }
  
  return (st.empty());
}

int main() {
    string exp;
    do{
    cout << "Enter any number of parantheses like: (())\n\tTo exit, press this menu type exit" << endl;
    cin >> exp;

    if (isbalanced(exp))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    } while(exp != "exit");
}