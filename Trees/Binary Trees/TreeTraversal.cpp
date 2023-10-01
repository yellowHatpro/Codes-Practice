#include "BinaryTree.h"

// PreOrder = node -> left ->right
// PostOrder = left->right->node
// InOrder = left->node->right

// DFS
void inorder(BinaryTreeNode<int> *root) {
  if (!root)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void preorder(BinaryTreeNode<int> *root) {
  if (!root)
    return;
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(BinaryTreeNode<int> *root) {
  if (!root)
    return;
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

// BFS
void levelorder(BinaryTreeNode<int> *root) {
  if (!root)
    return;
  queue<BinaryTreeNode<int> *> pendingTreeNodes;
  pendingTreeNodes.push(root);
  while (!pendingTreeNodes.empty()) {
    BinaryTreeNode<int> *front = pendingTreeNodes.front();
    pendingTreeNodes.pop();
    cout << front->data << " ";
    if (!front->left)
      pendingTreeNodes.push(front->left);
    if (!front->right)
      pendingTreeNodes.push(front->right);
  }
}
