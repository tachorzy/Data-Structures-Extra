#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;
//Mergesort for the LinkedList
void split(Node* headref, Node** list1, Node** list2){
  Node* ptr1 = headref, *ptr2 = headref->next;
  //by the end ptr1 will be mid, and ptr2 will be the tail.
  while(ptr2->next != nullptr && ptr2->next->next != nullptr){ 
    ptr1 = ptr1->next;
    ptr2 = ptr2->next->next;
  }
  *list1 = headref;
  *list2 = ptr1->next;
  ptr1->next = nullptr;
}

Node* merge(Node* list1, Node* list2){
  Node* temp;
  if(list1 == nullptr) //edgecase, same as left <= mid.
    return list2;
  if(list2 == nullptr) //edgecase, same as right <= high
    return list1;

  if(list1->data <= list2->data){ //if the left is less than the right
    temp = list1;
    temp->next = merge(temp->next, list2); // same as temp[i++] = a[left++]
  }
  else {
    temp = list2;
    temp->next = merge(list1, temp->next); //same as temp[i++] = a[right++]
  }
  return temp; //instead of deleting we're returning a new list.
}

void mergesort (Node** h){
  Node* headref = *h;
  Node* list1, *list2;
  if(headref == nullptr || headref->next == nullptr)
    return;
  split(headref, &list1, &list2); //(1) Divide
  mergesort(&list1);//(2) Recur
  mergesort(&list2);
  *h = merge(list1, list2); //(3) Conquer/Merge
}

int main() {
  LinkedList ll;
  ll.addAtEnd(ll.getHead(), "Y");
  ll.addAtEnd(ll.getHead(), "Z");
  ll.addAtEnd(ll.getHead(), "!");
  ll.addAtEnd(ll.getHead(), "C");
  ll.addAtEnd(ll.getHead(), "L");
  ll.addAtEnd(ll.getHead(), "B");
  ll.addAtEnd(ll.getHead(), "M");
  ll.addAtEnd(ll.getHead(), "T");
  Node* h = ll.getHead();
  mergesort(&h);
  ll.print(h);

} 