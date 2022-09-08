#include "Hash.h"
#include <iostream>

bool Hash::isfull(){
  int i = 0;
  while(arr[i] != nullptr)
    i++;
  if(i == size)
    return true;
  else 
    return false;
}

bool Hash::isempty(){
  int i = 0;
  while(arr[i] == nullptr)
    i++;
  if(i == size)
    return true;
  else 
    return false;
}



int Hash::hash(int k){
  return k % size;
}

int Hash::hash2(int k){
  return 3-(k%3); //it can be anything in the form of  C - (k%C)
}

//Dynamic mapping, time complexity is a constant O(1), but DM leads to unnecessary overwriting that causes the loss of data.
void Hash::dynamicmapping(int id, string data){
  if (isfull()){
    cout << "Hash Table is currently full. We couldn't add your key to the hashtable." << endl;
    return;
  }
  int index = hash(id);
  arr[index] = new Key;
  arr[index]->name = data;
}

//Linear probing, best case time complexity O(1). Wost case O(n)
void Hash::linearprobe(int id, string data){
  if (isfull()){
    cout << "Hash Table is currently full. We couldn't add your key to the hashtable." << endl;
    return;
  }
  int index = hash(id);
  while(arr[index] != nullptr)
    index = (index + 1) % size;  
  arr[index] = new Key;
  arr[index]->name = data;
}

//double hashing, best & average case O(1). Worst case is O(n).
void Hash::quadprobe(int id, string data){
  if (isfull()){
    cout << "Hash Table is currently full. We couldn't add your key to the hashtable." << endl;
    return;
  }
  
  int index = hash(id);
  int i = 1;
  while(arr[index] != nullptr){
    index = (index + i*i) % size;
    i++;
  }
  arr[index] = new Key;
  arr[index]->name = data;
}
//double hashing, best & average case O(1). Worst case is O(n) though you'll have to be extremely unlucky. 
void Hash::doublehash(int id, string data){
  if (isfull()){
    cout << "Hash Table is currently full. We couldn't add your key to the hashtable." << endl;
    return;
  }
  int index = hash(id);
  while(arr[index] != nullptr)
    index = (index + hash2(id)) % 10;
  arr[index] = new Key;
  arr[index]->name = data;
}
  
void Hash::search(int index, string key){
  if(index >= getSize()) {
    cout << key << " was not found in our catalog." << endl;
    return;
  }
  if(arr[index] != nullptr&& arr[index]->name == key){
    cout << key << " was found on aisle " << index << endl;
    return;
  }
  return search(index+1, key);
}
