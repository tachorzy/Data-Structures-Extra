#include <iostream>
#include "parkinglist.h"

using namespace std;

parkinglist::parkinglist() { 
  head = nullptr;
}
void parkinglist::addacarbeg(int y) { //lines 10 to 20 are on Exam 1
  //step 1 - get the car, create a car outside of the list
  car *tmp = new car;
  //step 2 - fill it
  tmp->year = y;
  tmp->next = nullptr;
  //step 3 - link it to the list
  if(head == 0) { head = tmp; }
  else {//if a list already exists then temp will become the new head
    tmp->next = head; 
    head = tmp;
  }
}

car *parkinglist::getHead(){ 
  return head; //more professional to do it this way, always keep head private.
}

void parkinglist::print() { 
  car *cu = head; //highly advised to save the head before
  while(cu != nullptr) { 
    cout << cu->year << endl;
    cu = cu->next; //the move
  }  
}

void parkinglist::printRecursively(car *p){ 
  if (p == 0) //base case
    return;
  else //repetition
    cout << p->year <<endl;
    printRecursively(p->next); //calling itself with p->next

}

void parkinglist::printRecursivelyReverse(car *p) { 
  if (p == 0) //base case
    return;
  else //repetition
    printRecursivelyReverse(p->next); 
    cout << p->year <<endl;
}

void parkinglist::addatend(int y) { 
  car *cu = head;
  car *temp = new car;
  while(cu->next->next != nullptr){ 
    cu = cu->next; //moving towards the right.
  }
  //once we've reached the second to last node:
  cu = cu->next;
  temp->year = y;
  temp->next = cu->next; //cu->next->next points the tail
  cu->next = temp; //now the tail becomes what we're adding.
}
