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
  void f(TreeNode *root, int low, int high, int &sum) {
    if (!root)
      return;
    if (root->val >= low and root->val <= high) {
      sum += root->val;
    }
    f(root->left, low, high, sum);
    f(root->right, low, high, sum);
  }

  int rangeSumBST(TreeNode *root, int low, int high) {
    int sum = 0;
    f(root, low, high, sum);
    return sum;
  }
};
