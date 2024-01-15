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
  int cnt = 0;
  void f(TreeNode *root, long long int targetSum) {
    if (!root)
      return;
    if (root->val == targetSum)
      cnt++;
    targetSum -= root->val;
    f(root->left, targetSum);
    f(root->right, targetSum);
  }

  int pathSum(TreeNode *root, long long int targetSum) {
    if (!root)
      return 0;
    f(root, targetSum);
    pathSum(root->left, targetSum);
    pathSum(root->right, targetSum);
    return cnt;
  }
};
