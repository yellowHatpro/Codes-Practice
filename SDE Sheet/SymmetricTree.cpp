#include <bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    
    bool isSymmetricH(TreeNode* p, TreeNode* q){
      if (!p || !q) return p==q;
      if (p->val!=q->val) return false;
      bool a = isSymmetricH(p->left, q->right);
      bool b = isSymmetricH(p->right, q->left);
      return a&&b;
  }
    
    bool isSymmetric(TreeNode* root) {
      if (!root) return true;
      return isSymmetricH(root->left,root->right);
    }
};
