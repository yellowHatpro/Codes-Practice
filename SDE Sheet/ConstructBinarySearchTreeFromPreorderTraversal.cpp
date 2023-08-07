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

    TreeNode* f(vector<int>& preorder, int &i, int upper_bound){
      if (i==preorder.size() || preorder[i]>upper_bound) return nullptr;
      TreeNode* root = new TreeNode(preorder[i++]);
      root->left = f(preorder,i,root->val);
      root->right = f(preorder,i,upper_bound);
      return root;
  }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
      int i = 0;
      return f(preorder,i,INT_MAX);
    }
};
