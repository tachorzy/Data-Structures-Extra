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

    int getMax(Node* cu){
      if(cu->right == nullptr && cu == root)
        return root->val;
      if(cu->right == nullptr)
        return cu->val;
      return getMax(cu->right);
    }






};