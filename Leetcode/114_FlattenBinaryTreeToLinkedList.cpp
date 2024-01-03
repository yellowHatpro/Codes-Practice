#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *prev = NULL;

  void flattenMorris(TreeNode *root) {
    // Using morris traversal
    TreeNode *curr = root;
    while (curr) {
      if (curr->left) {
        TreeNode *prev = curr->left;
        while (prev->right) {
          prev = prev->right;
        }
        prev->right = curr->right;
        curr->right = curr->left;
      }
      curr = curr->right;
    }
  }

  void flatten(TreeNode *root) {
    if (!root)
      return;
    flatten(root->right);
    flatten(root->left);
    root->right = prev;
    root->left = NULL;
    prev = root;
  }
};
