#include <string>

using namespace std;

struct Node { 
  char data;
  Node* next;
};

class Queue {
  private:
    Node* front;
    Node* rear;
  public:
    Queue() { front = nullptr, rear = nullptr; }
    Node* getFront() { return front; }
    int getSize();
    bool isempty() { return front==nullptr;}
    void enQueue(char data);
    void deQueue();
    void print(Node* headref);
    void search(char);
};