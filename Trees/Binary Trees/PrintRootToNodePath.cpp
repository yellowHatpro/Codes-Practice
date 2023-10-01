#include "BinaryTree.h"

// Do a simple traversal: Preorder one. add the root and do 2 recursive calls on
// left and right of root, if both recursive calls return false pop from array
// and return false. If we reach even one true, return true.

bool getPath(BinaryTreeNode<int> *root, vector<int> &arr, int x) {
  if (!root)
    return false;
  arr.push_back(root->data);
  if (root->data == x)
    return true;
  bool a = getPath(root->left, arr, x);
  bool b = getPath(root->right, arr, x);
  if (a || b)
    return true;
  if (a == b && a == false) {
    arr.pop_back();
    return false;
  }
}
