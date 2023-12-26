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
  void calcGst(TreeNode *root, int &sum) {
    if (!root)
      return;
    calcGst(root->right, sum);
    int currVal = root->val;
    root->val += sum;
    sum += currVal;
    calcGst(root->left, sum);
  }

  TreeNode *bstToGst(TreeNode *root) {
    int sum = 0;
    calcGst(root, sum);
    return root;
  }
};
