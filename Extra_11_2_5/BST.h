using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;
  Node(int key) { val = key, left = right = nullptr; }  
};

class BST {
private:
public:
  Node* root;
  //Node* getRoot(){ return root; }
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

  int findLowestCommonAncestor(Node* cu, Node* n1, Node* n2){
    if(cu == nullptr)
      return 0;
    if(n1->val < cu->val && n2->val < cu->val)
      return findLowestCommonAncestor(cu->left, n1, n2);
    else if (n1->val > cu->val && n2->val > cu->val)
      return findLowestCommonAncestor(cu->right, n1, n2);

    return cu->val;
  }
};