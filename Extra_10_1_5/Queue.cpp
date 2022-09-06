#include "Queue.h"
#include <iostream>

using namespace std;

int Queue::getSize() {
  int c = 0;
  Node* cu = front;
  while(cu->next != nullptr) {
    cu = cu->next;
    c++;
  }
  return c;
}

void Queue::enQueue(char data) {
  Node* temp = new Node();
  temp->data = data;
  temp->next = nullptr;

  if(isempty()) {
    front = rear = temp;
    return;
  }
  
  rear->next = temp;
  rear = temp;
}
void Queue::deQueue() {
  if(front == nullptr)
    return;

  Node* temp = new Node();
  temp = front;
  front = front->next;

  if(front == nullptr)
    rear = nullptr;

  delete temp;
}


void Queue::print(Node* headref) {
  if(headref == nullptr)
    return;
  cout << headref->data << " ";
  print(headref->next);
}
void Queue::search(char target){
  int c = 0;
  Node* cu = front;
  while(cu->next != nullptr && cu->data != target) {
    cu = cu->next;
    c++;
  }
  if(c == getSize() && rear->data != target)
    cout << "Sorry but the person you are looking for isn't in the queue." << endl;
  else { 
    cout << target << " is currently position in the queue is: (" << c+1 << "/" << getSize()+1 << ")" << endl; 
  }
}
