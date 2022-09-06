#include <string>

using namespace std;

struct Node { 
  string data;
  Node* next;
};

class QLinkedList {
  private:
    Node* front;
    Node* rear;
  public:
    QLinkedList() { front = nullptr, rear = nullptr; }
    Node* getFront() { return front; }
    int getSize();
    bool isempty() { return front==nullptr;}
    void enQueue(string data);
    void deQueue();
    void print(Node* headref);
    void search(string);
};