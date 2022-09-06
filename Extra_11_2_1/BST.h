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

  void print(Node* cu){
    if(cu == nullptr)
      return;
    cout << cu->val << " ";
    print(cu->left);
    print(cu->right);
    if(cu == root) cout << endl;
  }
  //invert is like an inorder traversal, but you are swapping the left with the right.
  void invert(Node* cu) {
    if(cu == nullptr)
      return;
    swap(cu->left, cu->right);
    invert(cu->left);
    invert(cu->right);
  }

};