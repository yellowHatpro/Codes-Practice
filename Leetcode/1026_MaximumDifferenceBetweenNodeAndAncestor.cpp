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
  int f(TreeNode *root, int mini, int maxi) {
    if (!root)
      return maxi - mini;
    mini = min(mini, root->val);
    maxi = max(maxi, root->val);
    return max(f(root->left, mini, maxi), f(root->right, mini, maxi));
  }

  int maxAncestorDiff(TreeNode *root) { return f(root, root->val, root->val); }
};
