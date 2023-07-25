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

bool searchInBST(BinaryTreeNode<int> *root, int x) {
  if (!root) return false;
  BinaryTreeNode<int>* temp = root;
  while(temp){
    if (temp->data==x) return true;
    else if (temp->data>x) {
      temp = temp->left;
    } else temp = temp->right;
  }
  return false;
}
