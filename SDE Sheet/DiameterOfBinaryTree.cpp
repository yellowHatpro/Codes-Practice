#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
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
    int diameterOfBinaryTreeH(TreeNode* root,int &ans) {
      if (!root) return 0;
      int l = diameterOfBinaryTreeH(root->left, ans);
      int r = diameterOfBinaryTreeH(root->right, ans);
      ans = max(ans,l + r);
      return 1 + max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root){
      int ans = INT_MIN;
      diameterOfBinaryTreeH(root,ans);
      return ans;
  }
};
