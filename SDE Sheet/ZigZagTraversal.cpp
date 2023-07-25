#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
//  Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> res;
      queue<TreeNode*> q;
      if (!root) return {};
      q.push(root);
      int ltr = 1;
      while(!q.empty()){
        int n = q.size();
        vector<int> row;
        for(int i = 0; i < n; i++){
          TreeNode* node = q.front();
          q.pop();
          row.push_back(node->val);
          if(node->left) q.push(node->left);
          if(node->right) q.push(node->right);    
      }
        if (!ltr){
          reverse(row.begin(),row.end());
      }
      ltr=!ltr;
      res.push_back(row);
     }
    return res;
    }
  };

