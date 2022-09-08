#include <queue>

using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;
  int h;
  Node(int key) { val = key; left = right = nullptr; h = 1; }
};

class AVL{
  public:
    Node* root;
    bool isempty() {return (root == nullptr);}
    int max(int a, int b) {return (a > b) ? a : b;}
    int height(Node*);
    int balancefactor(Node*);
    Node* leftRotation(Node*);
    Node* rightRotation(Node*);
    Node* insert(Node*, int);
    Node* minNode(Node* n);
    Node* deleteNode(Node*, int);
    void printlevelorder(Node*);
};

int AVL::height(Node* cu){
  if(cu == nullptr)
    return 0;
  int lh = height(cu->left);
  int rh = height(cu->right);
  return (lh > rh) ? 1 + lh : 1 + rh;
}

int AVL::balancefactor(Node* n){
  if (n == nullptr)
    return 0;
  return height(n->left) - height(n->right);
}

Node* AVL::leftRotation(Node* vn){
  Node* rightChild = vn->right;
  Node* temp = rightChild->left;
  rightChild->left = vn;
  vn->right = temp;
  vn->h = max(height(vn->left), height(vn->right));
  rightChild->h = max(height(rightChild->left), height(rightChild->right));
  if(vn == root)
    root = rightChild;
  return rightChild;
}

Node* AVL::rightRotation(Node* vn){
  Node* leftChild = vn->left;
  Node* temp = leftChild->right;
  leftChild->right = vn;
  vn->left = temp;

  vn->h = max(height(vn->left), height(vn->right));
  vn->h = max(height(leftChild->left), height(leftChild->right));
  if(vn == root)
    root = leftChild;
  return leftChild;
}

Node* AVL::insert(Node* cu, int key){
  if(isempty())
    return root = new Node(key);
  if(cu == nullptr)
    return new Node(key);
  if(key < cu->val)
    cu->left = insert(cu->left, key);
  else if(key > cu->val)
    cu->right = insert(cu->right, key);
  else
    return cu;
  //update the height.
  cu->h = max(height(cu->left), height(cu->right));
  //now assess the balance factor, and rebalancing
  int bf = balancefactor(cu);
  //balanced if -1 <= bf <= 1
  if(bf > 1 && key < cu->left->val)
    return rightRotation(cu);

  if (bf > 1 && key > cu->left->val){
    cu->left = leftRotation(cu->left);
    return rightRotation(cu);
  }

  if(bf < -1 && key > cu->right->val)
    return leftRotation(cu);

  if(bf < -1 && key < cu->right->val){
    cu->right = rightRotation(cu->right);
    return leftRotation(cu);
  }
  return cu;
}

Node* AVL::minNode(Node* n){
  while(n->left)
    n = n->left;
  return n;
}

Node* AVL::deleteNode(Node* cu, int key){
  if(cu == nullptr)
    return cu;
  if(key < cu->val)
    cu->left = deleteNode(cu->left, key);
  else if(key > cu->val)
    cu->right = deleteNode(cu->right, key);
  else { //if key == cu->val ---> delete cu
    if(!cu->left || !cu->right){ // <= 1 children.
      Node* temp = cu->left ? cu->left : cu->right;
      if(temp == nullptr) {
        temp = cu; 
        cu = nullptr;
      }
      else 
        *cu = *temp;
      free(temp);
    }
    else {
      Node* temp = minNode(cu->right);
      cu->val = temp->val;
      cu->right = deleteNode(cu->right, temp->val);
    }
  }

  if(cu == nullptr)
    return cu;

  cu->h = max(height(cu->left), height(cu->right));
  int bf = balancefactor(cu);
  //Left Left
  if(bf > 1 && balancefactor(cu->left) >= 0)
      return rightRotation(cu);
  //Left Right
  if (bf > 1 && balancefactor(cu->left) < 0) {
    cu->left = leftRotation(cu->left);
    return rightRotation(cu);
  }
  //Right Right
  if(bf < -1 && balancefactor(cu->right) <= 0)
      return leftRotation(cu);
  if(bf < -1 && balancefactor(cu->right) > 0){
    cu->right = rightRotation(cu->right);
    return leftRotation(cu); 
  }

  return cu;
}

void AVL::printlevelorder(Node* cu){
  if(cu == nullptr) {
    cout << "\tThe tree is currently empty. Press (1) to fill it." << endl;
    return;
  }
  queue<Node*> q;
  q.push(root);

  while(!q.empty()){
    int s = q.size();
    while(s > 0){
      Node* n = q.front();
      cout << n->val << " ";
      q.pop();
      if(n->left)
        q.push(n->left);
      if(n->right)
        q.push(n->right);
      s--;
    }
    cout << endl;
  }
}