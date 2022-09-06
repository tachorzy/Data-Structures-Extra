#include <iostream>

using namespace std;

/*make a menu: 1 for summation, 2 for factorial, 3 for exit
  2 recursive functions. You cna customize it all you want, e.g. add a recursive function for division what ever.
*/

int summation(int n){
  if (n == 0)
    return n;
  return (n + summation(n-1));
}

int factorial(int n){ 
  if (n == 0)
    return 1;
  return (n* factorial(n-1));
}


int main() {
  //menu using a do while loop
  int userNum;
  int userInput;
  
  do { 
    cout << "Hello, please choose one of the following\n1. Summation\n2. Factorial\n3. Exit" << endl;
    cin >> userInput;
    switch(userInput) { 
      case 1:
        cout << "Please choose a number for your summation" <<endl;
        cin >> userNum;
        cout << summation(userNum)<< endl;
        break;
      case 2:
        cout << "Please choose a number for your factorial" <<endl;
        cin >> userNum;
        cout << factorial(userNum)<< endl;
        break;
      case 3: 
        cout << "Bye!" << endl;
        break;
    }
  }
  while (userInput != 3);

}