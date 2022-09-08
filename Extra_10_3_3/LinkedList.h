#include <string>
#include <iostream>

using namespace std;

struct Order {
  int orderID;
  string menuItem;
  Order* next;
  Order* prev;
};

class LinkedList {
  private: 
    Order* head;
    Order* tail;
  public: 
    LinkedList(){ head = tail = nullptr;}
    ~LinkedList(){}
    bool isempty(){ return (head == nullptr);}
    Order* getHead() { return head;}
    Order* getTail() { return tail; }
    
    int getLength(Order* headref, int count=0) {
      if(headref == nullptr)
        return count;
      return getLength(headref->next, ++count);
    }
    void addAtBeg(Order* headref, int orderID, string item) {
      Order* newNode = new Order();
      newNode->orderID = orderID;
      newNode->menuItem = item;
      if(isempty()){
        head = headref = newNode;
        return;
      }
      if(headref->prev == nullptr){
        headref->prev = newNode;
        newNode->next = headref;
        head = newNode;
        return;
      }
      return addAtBeg(headref->next, orderID, item);
    }
    
    bool delAtVal(Order* headref, int orderID) {
      if(isempty() || headref == nullptr)
        return false;
      if(headref->orderID != orderID)
        return delAtVal(headref->next, orderID);
      else
        if(head == headref) {
          head = headref->next;
          head->prev = nullptr;
          delete headref;
        }
        else if(tail == headref){
          tail = headref->prev;
          tail->next = nullptr;
          delete headref;
        }
        else {
          headref->prev->next = headref->next;
          headref->next->prev = headref->prev;
          delete headref;
        }
        return true;
    }
    
    void print(Order* headref) {
      if(isempty() || headref == nullptr)
        return;
      cout << "ORDER#" << headref->orderID << "\n" << headref->menuItem << endl;
      return print(headref->next);
    }

    bool search(Order* headref, int key) {
      if(isempty()){
        cout << "this receipt is blank. Go yell at the cashier." << endl;
        return false;
      }
      if(headref == nullptr)
        return false;
      if(headref->orderID == key)
        return true;
      return search(headref->next, key);
    }
};