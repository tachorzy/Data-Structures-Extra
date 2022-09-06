#include <vector>

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
    if(isempty())
      return root = new Node(n);
    if(cu == nullptr)
      return new Node(n);
    else if(n > cu->val)
      cu->right = insert(cu->right, n);
    else if (n < cu->val)
      cu->left = insert(cu->left, n);

    return cu;
  }

  void inorder(Node* cu, vector<int>& v){
    if(cu == nullptr)
      return;
    inorder(cu->left, v);
    v.push_back(cu->val);
    inorder(cu->right, v);
  }

  void preorder(Node* cu, vector<int>& v, int *i){
    if(cu == nullptr)
      return;
    cu->val = v.at(++*i);
    preorder(cu->left, v, i);
    preorder(cu->right, v, i);
  }

  void toMinHeap(Node* cu){
    if(cu == nullptr)
      return;
    vector<int> v;
    inorder(cu, v);
    int i = -1;
    preorder(cu, v, &i);
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