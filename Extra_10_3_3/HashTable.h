#include "LinkedList.h"
#include <string>
#include <iostream>
#include <fstream>

class HashTable {
  private:
    int size = 10;
    LinkedList** arr;
  public:
    HashTable(int s){
      size = s;
      arr = new LinkedList*[size];
    }
    bool isfull();
    bool isempty();
    int getSize() { return size;}
    int hash(int);
    void fill(LinkedList* receipt, int orderID); 
    int search(int index, int key);
    //bool remove(int index, int key);
    //ignore this func:
    void editOrder(int key, string cmd);
};