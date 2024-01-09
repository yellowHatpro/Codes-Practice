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
  void f(TreeNode *root, vector<int> &v) {
    if (!root)
      return;
    if (!root->left and !root->right) {
      v.push_back(root->val);
    }
    f(root->left, v);
    f(root->right, v);
  }

  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> l1;
    vector<int> l2;
    f(root1, l1);
    f(root2, l2);
    return l1 == l2;
  }
};
