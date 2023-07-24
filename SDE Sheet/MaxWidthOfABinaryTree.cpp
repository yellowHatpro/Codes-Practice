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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, long long int>> q;
        q.push({root,0});
        while(!q.empty()){
        	int n = q.size();
        	int minimumInTheLevel = q.front().second;
        	int l,r;
        	for (int i = 0; i < n; ++i)
        	{	
        		auto [tree,idx] = q.front();
        		idx-=minimumInTheLevel;
        		q.pop();
        		if (i==0) l = idx;
        		if (i==n-1) r = idx;
        		if (tree->left) q.push({tree->left,2*idx+1});
        		if (tree->right) q.push({tree->right, 2*idx+2});
        	}
        	ans = max(ans,r-l+1);
        }
        return ans;
    }
};
