#include <bits/stdc++.h>
#define INT_MAX 1e8
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
    
    int f(TreeNode* root, bool nodeCam, bool parentCam, map<tuple<TreeNode*,bool,bool>,int> &dp){
    if (!root){
      if (nodeCam) return INT_MAX;
      return 0;
    }
    if (dp.find({root,nodeCam,parentCam})!=dp.end()) return dp[{root,nodeCam,parentCam}];
    if (nodeCam){
      return dp[{root,nodeCam,parentCam}] = 1+min(f(root->left,1,1,dp),f(root->left,0,1,dp))+min(f(root->right,1,1,dp),f(root->right,0,1,dp));
    } else{
      if (parentCam){
        return dp[{root,nodeCam,parentCam}] = min(f(root->left,0,0,dp),f(root->left,1,0,dp)) + min(f(root->right,0,0,dp),f(root->right,1,0,dp));
      } else {
        int a = f(root->left,1,0,dp) + min(f(root->right,0,0,dp),f(root->right,1,0,dp));
        int b = f(root->right,1,0,dp) + min(f(root->left,0,0,dp),f(root->left,1,0,dp));

        return dp[{root,nodeCam,parentCam}] = min(a,b);
      }
    }
  }

    int minCameraCover(TreeNode* root) {
      map<tuple<TreeNode*,bool,bool>,int>dp;
      return min(f(root,0,0,dp),f(root,1,0,dp));
    }
};
