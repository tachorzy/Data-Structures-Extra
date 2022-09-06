#include <iostream>
#include "parkinglist.h"

using namespace std;
int main() {
  parkinglist cadi; //head is null, the list is empty now
  cadi.addacarbeg(2020);
  cadi.addacarbeg(2019);
  cadi.addacarbeg(2018); //you always know the head of the LinkedList
  cadi.addatend(2011);
  cadi.addatend(2009);
  cadi.print();
  cout << "  print recursively......\n";
  cadi.printRecursively(cadi.getHead());
  cout << endl;
  cout << "  print recursively in reverse order......\n";
  cadi.printRecursivelyReverse(cadi.getHead());
}