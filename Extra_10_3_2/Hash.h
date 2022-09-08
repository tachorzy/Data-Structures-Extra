#include <string>

using namespace std;

struct Key{
  string name;
};

class Hash{
  private:
    int size = 10;
    Key** arr;
  public:
    Hash(int s) {
      size = s;
      arr = new Key*[size];
    }
    int getSize() {return size;}
    bool isempty();
    bool isfull();
    int hash(int);
    int hash2(int);
    void dynamicmapping(int, string);
    void linearprobe(int, string);
    void quadprobe(int, string);
    void doublehash(int, string);
    void search(int, string);
};