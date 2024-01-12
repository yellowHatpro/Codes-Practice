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
  void f(TreeNode *root, int &cnt, int maxVal) {
    if (!root)
      return;
    if (root->val >= maxVal) {
      cnt++;
      maxVal = root->val;
    }
    f(root->left, cnt, maxVal);
    f(root->right, cnt, maxVal);
  }

  int goodNodes(TreeNode *root) {
    int cnt = 1;
    f(root->left, cnt, root->val);
    f(root->right, cnt, root->val);
    return cnt;
  }
};
