#include <bits/stdc++.h>
using namespace std;

 // Definition for a binary tree node.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> lvl;
            for (int i = 0; i < n; ++i)
            {   
                TreeNode* node = q.front();
                q.pop();
                lvl.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(lvl);
        }
        return ans; 
    }
};
