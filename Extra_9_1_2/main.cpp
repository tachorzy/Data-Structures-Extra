#include <iostream>

using namespace std;

int linearSearchRecursive(int a[], int n, int size){
  size --;
  if (size < 0)
    return -1;
  else if (a[size] == n)
    return size; //size being the right most indice
  return linearSearchRecursive(a, n, size);
}


int main() {
  int a[] = {0,2,3,6,8,12,21};
  int num;
  int size = *(&a + 1) - a;//Remember: the name of the array is a pointer to the first cell.

  cout << "Enter the number you would like to search" << endl;
  cin >> num;

  int result = linearSearchRecursive(a, num, size);
  
  if(result == -1 )
    cout << "the number " << num << " was not found in the array" << endl;
  else
    cout << "The index of the number " << num << " is: " << result << endl;
}