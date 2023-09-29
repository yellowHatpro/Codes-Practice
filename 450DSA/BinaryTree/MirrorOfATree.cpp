#include <bits/stdc++.h>
using namespace std;

template <class T> class BinaryTreeNode {
public:
  T data;
  BinaryTreeNode<T> *left;
  BinaryTreeNode<T> *right;

  BinaryTreeNode(T data) {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

void mirrorTree(BinaryTreeNode<int> *root) {
  if (!root)
    return;
  BinaryTreeNode<int> *left = root->left;
  BinaryTreeNode<int> *right = root->right;
  root->left = right;
  root->right = left;
  mirrorTree(root->left);
  mirrorTree(root->right);
}
