#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
  pair<TreeNode *, int> f(TreeNode *root) {
    if (!root) {
      return {root, 0};
    }
    pair<TreeNode *, int> l = f(root->left);
    pair<TreeNode *, int> r = f(root->right);
    if (l.second == r.second) {
      return {root, l.second + 1};
    } else {
      if (l.second > r.second) {
        return {l.first, l.second + 1};
      } else {
        return {r.first, r.second + 1};
      }
    }
  }

  TreeNode *lcaDeepestLeaves(TreeNode *root) {
    if (!root || (!root->left && !root->right))
      return root;
    pair<TreeNode *, int> res = f(root);
    return res.first;
  }
};
