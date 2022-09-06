struct car { 
  int year;
  car *next;
};

class parkinglist{ 
  private: 
    car *head;
  public: 
    parkinglist();
    car * getHead();
    void addacarbeg(int); //passing the private data members of the car
    void print();
    void printRecursively(car *p);
    void printRecursivelyReverse(car *p);
    void addatend(int y); //extra!!! do it at home
};
