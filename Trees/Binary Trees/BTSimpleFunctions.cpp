#include "BinaryTree.h"

void printTree(BinaryTreeNode<int> *root) {
  if (root == NULL)
    return;
  cout << root->data << ":";
  if (root->left != NULL)
    cout << root->left->data << " ";
  if (root->right != NULL)
    cout << root->right->data << " ";
  printTree(root->left);
  printTree(root->right);
}

int main() {
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
  BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
  BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
  root->left = node1;
  root->right = node2;
  printTree(root);
  delete root;
}
