#include <bits/stdc++.h>
using namespace std;

vector<int> getInorder(TreeNode *root) {
  vector<int> inOrder;
  TreeNode *curr = root;
  while (curr) {
    if (!curr->left) {
      inOrder.push_back(curr->val);
      curr = curr->right;
    } else {
      TreeNode *prev = curr->left;
      while (prev->right && prev->right != curr) {
        prev = prev->right;
      }
      if (!prev->right) {
        prev->right = curr;
        curr = curr->left;
      } else {
        prev->right = NULL;
        inOrder.push_back(curr->val);
        curr = curr->right;
      }
    }
  }
  return inOrder;
}
