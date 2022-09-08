/*Stack implementation (ADT) using a dynamic array.*/

using namespace std;

class stack {
  private:
    char *elt;
    int top;
    int size;
  public: 
    stack(int s) {
      size = s; 
      elt = new char[s];
      top = -1;  //initialized to -1 as in empty.
    }
    bool isempty(){return (top == -1); }
    bool isfull() { return(top == size-1); }
    char peek(){
      if(!isempty())
        return elt[top];
    }
    int getSize() {
      return top;
    }
    bool push(char x) { 
      if(!isfull()){
        top++;//incrementing the "index of top"
        elt[top] = x;
        return true;
      }
      return false;
    }
    bool pop(){
      if(isempty())
        return false;

      top--;
      return true;
    }
    bool popAll(){
      if(isempty())
        return false;

      for(int i = 0; i < size; i++){
        top = -1;
      }
      return true;
    }

  void print(int top){ //FILO - first in last out.
    if(isempty()) //edge case 
      return;
    if(top == -1) //base case
      return;
    cout << elt[top] << endl;
    print(top-1);
  }
};