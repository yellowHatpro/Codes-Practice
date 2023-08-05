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

    vector<TreeNode*> f(int l, int r){
    vector<TreeNode*> res;
      if (l==r) return {new TreeNode(l)};
      if (l>r) return {nullptr};
      for(int i = l; i <=r; i++){
        for(auto leftTreeNode: f(l,i-1)){
          for(auto rightTreeNode: f(i+1,r)){
            TreeNode* root = new TreeNode(i);
            root->left = leftTreeNode;
            root->right = rightTreeNode;
            res.push_back(root);
          }
        }
      }
      return res;
    }

    vector<TreeNode*> generateTrees(int n) {
      return f(1,n);
    }
};
