#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        bool left = true;
        while(!pendingNodes.empty()){
  			int n = pendingNodes.size();
  			vector<int> row(n);
  			for (int i = 0; i < n; ++i)
  			{
  				TreeNode* front = pendingNodes.front();
  				pendingNodes.pop();
  				int index;
  				if (left)
  				{
  					index = i;
  				}
  				else {
  					index = n-i-1;
  				}
  				row[index] = front->val;

  				if (front->left) pendingNodes.push(front->left);
  				if (front->right) pendingNodes.push(front->right);
  			}
  			left = !left;
  			res.push_back(row);

        }
        return res;
    }
};