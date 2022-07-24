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

//Simple DFS

class Solution {
public:
	void hasPathSumHelper(TreeNode* root, int targetSum, bool& res){
		if (!root) return;
		if (!root->left && !root->right && root->val == targetSum)
		{
			res = true;
		}
		hasPathSumHelper(root->left, targetSum - root->val,res);
		hasPathSumHelper(root->right, targetSum - root->val,res);

	}

    bool hasPathSum(TreeNode* root, int targetSum) {
        int cnt = 0;
        bool res = false;
       hasPathSumHelper(root,targetSum,res);
       return res;
    }
};