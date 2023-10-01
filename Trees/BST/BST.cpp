/*
Binary Search Tree (BST)
BST are recursive data structures.
BST is a binary tree. Same BinaryTreeNode
BST is a complete binary tree.
*/

#include <bits/stdc++.h>
using namespace std;
class Node {
public:
  int data;
  Node *left;
  Node *right;
  Node(int data) {
    this->data = data;
    left = right = NULL;
  }
  Node *insert(Node *root, int data) {
    if (!root)
      return new Node(data);
    if (data < root->data) {
      root->left = insert(root->left, data);
    } else {
      root->right = insert(root->right, data);
    }
    return root;
  }

  // Inorder Traversal for BST is sorted
  void printBSTInOrder(Node *root) {
    if (!root)
      return;
    while (root) {
      printBSTInOrder(root->left);
      cout << root->data << " ";
      printBSTInOrder(root->right);
    }
  }
};
