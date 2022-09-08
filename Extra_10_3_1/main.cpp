/*
This is a program creating a hash table out of a dynamic array of "Packages", each package has an order# and a customer name. In the hashtable, there is a recursive search function that takes in an Order# as a key, a fill function that uses linear probing, and a remove function. Take care!
*/

#include <iostream>
#include "HashTable.h"

int main() {
  HashTable hash(10);

  hash.fill(100001, "guest001");
  hash.fill(100021, "simplord");
  hash.fill(110101, "tariq");
  hash.fill(19854, "guest002");
  hash.fill(10765, "cj");
  hash.fill(21706, "Mr. Probing");
  hash.fill(19165, "spikespeigel97");
  hash.fill(55438, "jeffbezos");
  hash.fill(87919, "Mr. Hash");
  hash.fill(3011, "imouttanames");

  //a menu to search and remove from the hashtable (locker)
  int menuInput, userID;
  do{
  cout << "Welcome to Amazon Locker Shasta, serving the University of Houston.\nIf you are a student or UH faculty please press 1." << endl;
  cin >> menuInput;
  if(menuInput == 1)
      cout << "Press One of the following:\n\t(1) to search for an order.\n\t(0) to exit." << endl;
      cin >> menuInput;
      if(menuInput == 1) {
        cout << "Please enter your order#." << endl;
        cin >> userID;
        int lockerNum = hash.search(0, userID);
        if(lockerNum != -1){
          cout << "Opening the locker to your package...\n" << endl;
          hash.remove(lockerNum, userID);
        }
      }
      cout << endl;
  }while(menuInput != 0);
}