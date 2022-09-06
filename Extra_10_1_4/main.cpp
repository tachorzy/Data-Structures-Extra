/*
Extra from the textbook: P-5.6 Implement the queue ADT with a singly linked list.
*/

#include <iostream>
#include "QLinkedList.h"

using namespace std;

int main() {
  QLinkedList q;
  q.enQueue("Tariq");
  q.enQueue("Nik");
  q.enQueue("Tristan");
  q.enQueue("Jacob");
  q.enQueue("Waldo");
  q.deQueue();
  q.print(q.getFront());
  cout << endl;
  q.search("Waldo");
  q.search("Tariq");
}