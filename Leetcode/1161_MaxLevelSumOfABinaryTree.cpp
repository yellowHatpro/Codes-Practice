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
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        int maxSum = INT_MIN;
        int lvl = 0;
        int res;

        while(!pendingNodes.empty()){
        	int n = pendingNodes.size();
        	int sum = 0;
        	for (int i = 0; i < n; ++i)
        	{
        		TreeNode* front = pendingNodes.front();
        		pendingNodes.pop();
        		sum+=front->val;
        		if(front->left) pendingNodes.push(front->left);
        		if(front->right) pendingNodes.push(front->right);

        	}
        	if (sum>maxSum)
        	{
        		maxSum = sum;
        	}
        }
        return maxSum;
    }
};