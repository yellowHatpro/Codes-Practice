#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// leftSubTree.cnt + rightSubTree.cnt + 1
// leftSubTree.weight + rightSubTree.weight + nodeW

class Solution {
public:
  int cnt = 0;
  pair<int, int> f(TreeNode *root) {
    if (!root)
      return {0, 0};
    if (!root->left and !root->right) {
      cnt++;
      return {1, root->val};
    }
    auto [cl, wl] = f(root->left);
    auto [cr, wr] = f(root->right);
    int c = cl + cr + 1;
    int w = wl + wr + root->val;
    if (w / c == root->val)
      cnt++;
    return {c, w};
  }

  int averageOfSubtree(TreeNode *root) {
    if (!root)
      return 0;
    if (!root->left and !root->right)
      return 1;
    f(root);
    return cnt;
  }
};
