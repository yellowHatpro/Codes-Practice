#include <bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root==p || root ==q) return root;
        TreeNode* a = lowestCommonAncestor(root->left,p,q);
        TreeNode* b = lowestCommonAncestor(root->right,p,q);
        if (!a) return b;
        else if (!b) return a;
        else return root;
    }
};