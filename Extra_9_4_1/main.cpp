
/*Just a small program with a recursive and non-recursive binary search, with a menu.*/

#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int size){ 
  int left = 0;
  int right = size - 1;

  while(left <= right) {
    int mid = (left + right) /2; //divide and conquer
    
    if(n == a[mid])
      return mid;
    else if (n > a[mid])
      left = mid + 1;
    else if (n < a[mid])
      right = mid -1;
  }
  return -1;
}

int binarySearchRecursive(int a[], int n, int left, int right){ 
  int mid = (left+right) /2;
  
  if (n == a[mid]) //base case
    return mid; 
  else if (n > a[mid]) //recursive case 1: divide & conquer
    return binarySearchRecursive(a, n, mid+1, right);
  else //recursive case 2: divide & conquer
    return binarySearchRecursive(a, n, left, mid-1);

  return -1; //if num is not present in the array return a -1
}

int main() {
  
  //menu using a do while loop
  int userNum;
  int userInput;
  
  int a[] = {0,2,3,6,8,12,21};
  int num;
  int size = *(&a + 1) - a;

  do { 
    cout << "Hello, please choose one of the following\n1. With Recursion\n2. Without Recursion\n3. Exit" << endl;
    cin >> userInput;
    switch(userInput) { 
      case 1:
        cout << "Please choose the number you want to search for" <<endl;
        cin >> userNum;
        cout << "The number " << userNum << " is at the index " << binarySearchRecursive(a, userNum, 0, size)<< endl;
        break;
      case 2:
        cout << "Please choose the number you want to search for" <<endl;
        cin >> userNum;
        cout << "The number " << userNum << " is at the index " << binarySearch(a, userNum, size)<< endl;
        break;
      case 3: 
        cout << "Bye!" << endl;
        break;
    }
  }
  while (userInput != 3);



}