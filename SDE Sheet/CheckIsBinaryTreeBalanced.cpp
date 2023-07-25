#include <bits/stdc++.h>
using namespace std;

  template <typename T>
  class BinaryTreeNode 
 {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

int height(BinaryTreeNode<int>* root){
  if (!root) return 0;
  return 1 + max(height(root->left),height(root->right));
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
  if (!root) return true;
  if (abs(height(root->left)-height(root->right))>1) return false;
  bool l = isBalancedBT(root->left);
  bool r = isBalancedBT(root->right);
  return l&&r;
  
}
