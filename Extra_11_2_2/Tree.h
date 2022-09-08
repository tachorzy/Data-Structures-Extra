#include <queue>

using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;
  Node(int key) { val = key, left = right = nullptr; }  
};

class Tree {
  public:
    Node* root;
    bool isempty() { return (root == nullptr);}
    //inserts into the Binary Tree with a level order traversal.
    Node* insert(int key) {
      if(isempty())
        return root = new Node(key);
      //bfs level order traversal (iterative)
      queue<Node*> q;
      q.push(root);
      while(!q.empty()){
        Node* cu = q.front();
        q.pop();
        if(cu->left)
          q.push(cu->left);
        else
          return cu->left = new Node(key);
        
        if(cu->right)
          q.push(cu->right);
        else
          return cu->right = new Node(key);
      }
    }

    int sumOfLeaves(Node* cu, int sum){
      if(cu == nullptr)
        return 0;
      if(!cu->left && !cu->right)
        return cu->val;
      return sumOfLeaves(cu->left, sum) + sumOfLeaves(cu->right, sum);
    }
    void printLeaves(Node* cu){
      if(cu == nullptr)
        return;
      else if(!cu->left && !cu->right)
        cout << cu->val << " ";
      else{
        printLeaves(cu->left); 
        printLeaves(cu->right);
      }

    }
    //level order printing stuff done here
    int height(Node* n){
      if(n == nullptr)
        return 0;
      int lh = height(n->left);
      int rh = height(n->right);
      //return 1 + max(lh, rh);
      if(lh > rh)
        return 1 + lh;
      else
        return 1 + rh;
    }

  void printlevelorder(Node* cu){
    if(cu == nullptr)
      return;
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




    
};