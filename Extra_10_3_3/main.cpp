/*A Hash Table (Restaurant Ticket Holder) of Linkedlists (receipts). Ignore the File I/O stuff and the code I've commented out. I might properly implement an input and command file to edit the hash and linkedlists at a future date.*/
#include <iostream>
#include <fstream>
#include "HashTable.h"

int main(int argc, char* argv[]) {
  HashTable ticketholder(4);
  LinkedList r1, r2, r3, r4, r5, r6, r7, r8, r9, r10;

  r1.addAtBeg(r1.getHead(), 1001, "2x Mr Brown's Classic Hashbrown");
  r1.addAtBeg(r1.getHead(), 1001, "1x Chocolate Hash");
  r2.addAtBeg(r1.getHead(), 1002, "1x Heap O' Hash");
  r3.addAtBeg(r3.getHead(), 1003, "2x Double Hash'd Hash (easy on the collisions)");
  r3.addAtBeg(r3.getHead(), 1003, "1x Mr Brown's Classic Hashbrown");
  r4.addAtBeg(r4.getHead(), 1004, "1x Shell's Assorted Hash");
  r4.addAtBeg(r4.getHead(), 1004, "1x Triple Hash'd Hash");

  ticketholder.fill(&r1, 1001), ticketholder.fill(&r2, 1002), 
    ticketholder.fill(&r3, 1003), ticketholder.fill(&r3, 1004);
  
  if(ticketholder.search(0, 1001));

  /*
  ifstream inFile;
  inFile.open("input1.txt");
  ifstream cmdFile;
  inFile.open("command1.txt");
  int ordernum = 1000;
  string line;
  LinkedList temp;
  
  while(getline(inFile, line)){
    if (line.find("ORDER") == string::npos){
      cout << "line is " << line << endl;
      temp.addAtBeg(temp.getHead(), ordernum, line);
      cout << "temp's head" << temp.getHead()->orderID << endl;
    }
    else{
      LinkedList temp;
      ticketholder.fill(&temp, ordernum);
      ordernum++;
    }
  }
  */  
  /*
  //handles command file commands
  while(getline(cmdFile, line)){
    string key = line.substr(line.find('{')+1, line.find(':') - line.find('{') - 1);
    int id = stoi(key);
    ticketholder.editOrder(id, line);
  }*/
}