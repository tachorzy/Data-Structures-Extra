#include "HashTable.h"

bool HashTable::isFull() {
  int i = 0;
  while(arr[i] != nullptr)
    i++;
  if(i == size)
    return true;
  else 
    return false;
}
bool HashTable::isEmpty() {
  int i = 0;
  while(arr[i] == nullptr) {
    i++;
  }
  if(i-1 == size)
    return true;
  else 
    return false;
}

int HashTable::hash(int key) {
  return key % size;
}

void HashTable::fill(int orderID, string name){
    if(isFull()){
      cout << "the hash is full. We couldn't make that order for you " << name << ". Please try again later!"<< endl;
      return;
    }
    int index = hash(orderID); //(1) hash the ID
    while(arr[index] != nullptr)//(2) apply Linearing probing
      index = (index +1) % size;
    //(3) fill at an appropriate index
    arr[index] = new Package();
    arr[index]->orderID = orderID;
    arr[index]->customer = name;
}
int HashTable::search(int index, int key) {
  if(index >= getSize()){
    cout << "Your package was not found at this Amazon Locker location." << endl;
    return -1;
  }

  if(arr[index] != nullptr && arr[index]->orderID == key) {
    cout << "Your package" << " (ORDER#" << arr[index]->orderID << ")" << " has been found in our database and is currently in locker #" << index << endl;
    return index;
  }

  return search(index+1, key);
}

bool HashTable::remove(int index, int key) {
  if(isEmpty())
    return false;
  if(arr[index]->orderID == key){ // O(1) where we just take the index and delete
    cout << "Please retrieve your package from locker #" << index << endl;
    cout << "\tThank you for choosing Amazon™, " << arr[index]->customer << "!\n\t\t*as if you have any other choice. MUHAHAHAHA." << endl; 
    arr[index] = nullptr;
    return true;

  }
  else{ //if there's a mishap in the system, we'll use linear probing to find the item. O(n)
    int c = 0, i = key%size;
    while(c < size){
      if(arr[i] == nullptr)
        i = (i+1) %size;
      else if(arr[i]->orderID != key)
        i = (i+1)%size;
      else {
        arr[i] = nullptr;
        return true;
      }
    }
  }
  return false;
}
