// In unival trees, all the nodes, below the root node, have the same value as
// the data of the root.

#include <bits/stdc++.h>
using namespace std;
template <typename T> class BinaryTreeNode {
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
bool helper(BinaryTreeNode<int> *root, int &count) {
  if (root == NULL) {
    return true;
  }
  if (root->left == NULL && root->right == NULL) {
    count++;
    return true;
  }
  bool l = false;
  bool r = false;
  l = helper(root->left, count);
  r = helper(root->right, count);
  if (root->left != NULL && root->right != NULL) {
    if (l && r && root->left->data == root->data &&
        root->right->data == root->data) {
      count++;
      return true;
    } else
      return false;
  } else if (root->right != NULL) {
    if (root->right->data == root->data && r) {
      count++;
      return true;
    } else
      return false;
  }

  else if (root->left != NULL) {
    if (root->left->data == root->data && l) {
      count++;
      return true;
    } else
      return false;
  }
  return false;
}

int countUnivalTrees(BinaryTreeNode<int> *root) {
  int count = 0;
  helper(root, count);
  return count;
}

int main() {
  cout << endl;
  return 0;
}

