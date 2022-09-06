using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;
  Node(int key) { val = key, left = right = nullptr; }  
};

class Tree {
private:
  Node* root;
public:
  Node* getRoot(){ return root; }
  bool isempty() { return (root == nullptr); }
  
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
  int depth(Node* cu, Node* node, int c) {
    if(root == node)
      return 0;
    if(cu == node)
      return c-1;  
    if(node->val < cu->val) {
      c++;
      return depth(cu->left, node, c);
    }

    if(node->val > cu->val) {
      c++;
      return depth(cu->right, node, c);
    }

  }
  
  Node* search(Node* cu, int key){
    if(cu == nullptr)
      return 0;
    if (cu->val == key)
      return cu;
    if(key < cu->val)
      return search(cu->left, key);
    else if(key > cu->val)
      return search(cu->right, key);
  }
};