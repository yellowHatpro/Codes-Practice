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

struct NodeValue {
  int maxi;
  int mini;
  int size;
  NodeValue(int maxi, int mini, int size)
      : maxi(maxi), mini(mini), size(size) {}
};

class Solution {
private:
  NodeValue f(TreeNode *root) {
    if (!root) {
      return NodeValue(INT_MIN, INT_MAX, 0);
    }
    NodeValue leftTree = f(root->left);
    NodeValue rightTree = f(root->right);
    if (leftTree.maxi < root->val and root->val < rightTree.mini) {
      return NodeValue(max(rightTree.maxi, root->val),
                       min(leftTree.mini, root->val),
                       leftTree.size + rightTree.size + 1);
    }
    return NodeValue(INT_MAX, INT_MIN, max(leftTree.size, rightTree.size));
  }

public:
  int largestBSTSubtree(TreeNode *root) { return f(root).size; }
};
