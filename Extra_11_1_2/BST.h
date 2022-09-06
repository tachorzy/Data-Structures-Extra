using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;
  Node(int key) { val = key, left = right = nullptr; }  
};

class BST {
  private:
    Node* root;
  public:
    Node* getRoot(){ return root; }
    bool isempty(){ return (root == nullptr); }

    Node* insert(Node* cu, int n) {
        if(isempty()){
          Node* newNode =  new Node(n);
          root = newNode;
          return newNode;
        }
        if(cu == nullptr)
          return new Node(n);
        else if(n > cu->val)
          cu->right = insert(cu->right, n);
        else if (n < cu->val)
          cu->left = insert(cu->left, n);

        return cu;
    }

    bool search(Node* cu, int key){
      if(cu == nullptr)
        return false;
      if (cu->val == key)
        return true;
      if(key < cu->val)
        return search(cu->left, key);
      else if(key > cu->val)
        return search(cu->right, key);
    }

  
};