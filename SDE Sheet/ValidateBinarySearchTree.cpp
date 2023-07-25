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

    bool f(TreeNode* root, TreeNode* l, TreeNode* r){
      if (!root) return true;
      if (l && root->val <=l->val) return false;
      if (r && root->val >= r->val) return false;
      return f(root->left, l,root) && f(root->right,root,r);
  }  

    bool isValidBST(TreeNode* root) {
      return f(root, nullptr, nullptr);
  }
};
