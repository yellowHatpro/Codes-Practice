#include <bits/stdc++.h>
using namespace std;

// Time Complexity O(logn)^2
// Logn for traversing, and Logn for finding height
// Space is O(height) = O(logn)

int findHeightLeft(TreeNode *node) {
  int h = 0;
  while (node) {
    h++;
    node = node->left;
  }
  return h;
}

int findHeightRight(TreeNode *node) {
  int h = 0;
  while (node) {
    h++;
    node = node->right;
  }
  return h;
}

int countNodes(TreeNode *root) {
  int lH = findHeightLeft(root);
  int rH = findHeightRight(root);
  if (lH != rH)
    return 1 + countNodes(root->left) + countNodes(root->right);
  else
    return (1 << lH) - 1;
}
