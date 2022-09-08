#include "HashTable.h"

using namespace std;

bool HashTable::isfull() {
  int i = 0;
  while(arr[i] != nullptr)
    i++;
  if(i == size)
    return true;
  else 
    return false;
}
bool HashTable::isempty() {
  int i = 0;
  while(arr[i] == nullptr)
    i++;
  if(i == size)
    return true;
  else
    return false;
}

int HashTable::hash(int id) {
  return id % size;
}

void HashTable::fill(LinkedList* receipt, int orderID) {
  if(isfull()) {
    cout << "THERE'S TOO MANY CUSTOMERS, WE CAN'T TAKE ANYMORE ORDERS" << endl;
    return;
  }
  int index = hash(orderID);
  int i = 1;
  while(arr[index] != nullptr){
    index = (index + i*i) % size;
    i++;
  }
  arr[index] = receipt;
}

int HashTable::search(int index, int key){
  if(isempty()){
    cout << "couldn't find what you're lookin for. GET BACK TO WORK!" << endl;
    return -1;
  }
  if(index >= arr[index]->getHead()->orderID && arr[index]->getHead() == nullptr) {
    cout << "ORDER#" << key << "wasn't found in the ticketholder." << endl;
    return -1;
  }

  if(arr[index]->getHead()->orderID == key && arr[index] != nullptr) {
    cout << "ORDER#" << key << " found at slot #" << index << " of the ticketholder." << endl;
    return index;
  }
  return search(index+1, key);
}

/*
bool HashTable::remove(int index, int key) {
  LinkedList* receipt = arr[index];
  int receiptLength = receipt->getLength(receipt->getHead());
  if(isempty()){
    cout << "Trying to remove a blank receipt?? Are ya' crazy? THAT PAPER COSTS MORE THAN YOU! GET BACK TO WORK!" << endl;
    return false;
  }
  if(index >= receiptLength)
    return -1;
  if(receipt->search(receipt->getHead(), key) == key)
    return true;
  return remove(index+1, key);
}*/

/*take orders from the command file.
void HashTable::editOrder(int key, string cmd){
  if(isempty()) { cout << "hash is empty" << endl; return; }
  int index = search(0, key);
  if(index != -1){
    if(cmd.find("addToOrder")) {
      string newItem = cmd.substr(cmd.find(':')+1, cmd.find('}') - cmd.find(':') - 1);
      //arr[index]->addAtBeg(arr[index]->getHead(), key, newItem);
    }
    else if(cmd.find("add")) {
      string newItem = cmd.substr(cmd.find(':')+1, cmd.find('}') - cmd.find(':') - 1);
      //arr[index]->addAtBeg(arr[index]->getHead(), key, newItem);
    }
  }
  */
