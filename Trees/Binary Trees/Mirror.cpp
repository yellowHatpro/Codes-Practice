#include "BinaryTree.h"

void mirrorBinaryTree(BinaryTreeNode<int> *root) {
  if (root == nullptr) {
    return;
  }
  mirrorBinaryTree(root->left);
  mirrorBinaryTree(root->right);
  BinaryTreeNode<int> *temp = root->left;
  root->left = root->right;
  root->right = temp;
  return;
}
