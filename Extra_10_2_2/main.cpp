//Extra that takes a calculates and compares the execution time of an insertionsort and a insertionsort

#include <iostream>
#include <ctime>
#include <set>
#include <iomanip>

using namespace std;

void insertionSort(int a[], int n) { //copy and pasted from the slides
  for (int i = 1; i < n; i++) {
    int next = a[i];  int j;
    for (j = i-1; j >= 0 && a[j] > next; j--)
     a[j+1] = a[j];
    a[j+1] = next;
  }
}

// shellsort implementation, copy and pasted from Google
int shellSort(int arr[], int N) { 
    for (int gap = N/2; gap > 0; gap /= 2) { 
      for (int i = gap; i < N; i += 1) { 
        int temp = arr[i]; 
        int j; 
        for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
          arr[j] = arr[j - gap];        
        arr[j] = temp; 
      } 
    } 
    return 0; 
} 

int main() {    
  int i = 1; 
  double sumOfInsertTime = 0, sumOfShellTime = 0;
  while(i <= 10) {
    //generating 1000 unique integers with the help of a set
    int arr[1000];
    set<int> s;
    int c = 0;
    while(c < 1000){
      int data = rand()%1001;
      if(s.find(data) == s.end()) {
        arr[c] = data;
        s.insert(data);
        c++;
      }
    }

    //measuring execution time
    time_t start = 0, end = 0;
    double insertionTime, shellTime;
    start = clock();
    insertionSort(arr, 1000);
    end = clock();
    insertionTime = double(end - start) / double(CLOCKS_PER_SEC);

    cout << "(" << i << ")" << "The execution time for insertion sort, given an array of 1000 unique random elements is: " << setprecision(5) << insertionTime << " seconds." << endl;

    time_t start2 = 0, end2 = 0;  
    start2 = clock();
    shellSort(arr, 1000);
    end2 = clock();
    
    shellTime = double(end2 - start2) / double(CLOCKS_PER_SEC);

    cout << "(" << i << ")" << "The execution time for shell sort, given an array of 1000 unique random elements is: " << setprecision(5) << showpoint << fixed << shellTime << " seconds." <<endl;

    cout << endl;

    cout << "(" << i << ")" << "The shellshort's execution time ran " << setprecision(1) << (shellTime/insertionTime) * 100 << "% faster than the insertionsort." << endl;
    sumOfInsertTime += insertionTime;
    sumOfShellTime += shellTime;
    i++;
  }

  cout << endl;
  cout << "On average the Insertion Sort's execution time for 10 arrays of 1000 unique integers was: " << setprecision(5) << showpoint << fixed << (sumOfInsertTime) * 10.0 << endl;

  cout << "On average the Shell Sort's execution time for 10 arrays of 1000 unique intergers was: " << setprecision(5) << showpoint << fixed << (sumOfShellTime) * 10.0 << endl;
}