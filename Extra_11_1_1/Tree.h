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
    if(isempty())
      return root =  new Node(n);
    if(cu == nullptr)
      return new Node(n);
    else if(n > cu->val)
      cu->right = insert(cu->right, n);
    else if (n < cu->val)
      cu->left = insert(cu->left, n);

    return cu;
  }

  void printInorder(Node* cu){
    if(cu == nullptr)
      return;
    printInorder(cu->left);
    cout << cu->val << " ";
    printInorder(cu->right);
    if(cu == root) cout << endl;
  }

  void printPostorder(Node* cu){
    if(cu == nullptr)
      return; 
    printPostorder(cu->left);
    printPostorder(cu->right);
    cout << cu->val << " ";
    if(cu == root) cout << endl;
  }

  void printPreorder(Node* cu){
    if(cu == nullptr)
      return;
    cout << cu->val << " ";
    printPreorder(cu->left);
    printPreorder(cu->right);
    if(cu == root) cout << endl;
  }
};