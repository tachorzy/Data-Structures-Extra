using namespace std;

struct letter { 
  char l;
  letter* next;
};

class mystack {
  private:
    letter* top;
  public:
    mystack() { top = nullptr; }
    letter* getTop(){return top;}
    bool isempty(){return (top == nullptr);}
    void push(char c) { 
      letter* temp = new letter(); //(1) creating
      temp->l = c; //(2) filling
      temp->next = top;
      top = temp; //top becomes our new top.
    }
    bool pop(char &c) { 
      if(isempty()) {
        cout << "the stack is currently empty." << endl;
        return false;
      }
      letter* temp = top;
      top = top->next;
      c = temp->l;
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

    /*
    void print(letter* top){
      if(isempty())
        cout << "The stack is empty." << endl;
      if(top == nullptr)
        return;
      cout << top->l << endl;
      print(top->next);
    }*/
};