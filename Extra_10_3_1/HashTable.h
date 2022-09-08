#include <string>
#include <fstream>
#include <iostream>

using namespace std;

struct Package {
  int orderID;
  string customer;
};

class HashTable {
  private:
    int size = 10;
    Package **arr;
  public:
    HashTable(int s) {
      size = s;
      arr = new Package*[size];
    }
    bool isFull();
    bool isEmpty();
    int getSize() {return size;}
    int hash(int);
    void fill(int, string); //Linear Probing
    void getData(ifstream& in);
    int search(int index, int key);
    bool remove(int index, int key);
};