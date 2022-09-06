using namespace std;

struct letter { 
  char l;
  letter* next;
};

class Stack { 
  private:
    letter* top;
  public:
    Stack() { top = nullptr; }
    letter* getTop(){return top;}
    bool isempty(){return (top == nullptr);}
    int getSize(){
      letter* cu = new letter();
      cu = top;
      int c = 0;
      while(cu->next != nullptr) {
        cu = cu->next;
        c++; 
      }
      return c;
    }

    void push(char c) { 
      letter* temp = new letter(); //(1) creating
      temp->l = c; //(2) filling
      temp->next = top;
      top = temp; //top becomes our new top.
    }
    bool pop() { 
      if(isempty()) {
        cout << "the stack is currently empty." << endl;
        return false;
      }
      letter* temp = top;
      top = top->next;
      delete temp;
      return true;
    }  
    void peek(){
      if(isempty()) {
        cout << "the stack is currently empty." << endl;
        return;
      }
      
      cout << top->l << endl;
    }
    void print() { 
      letter* cu = top;
      while (cu != nullptr){ 
        cout << cu->l << " ";
        cu = cu->next;
      }
    }
};