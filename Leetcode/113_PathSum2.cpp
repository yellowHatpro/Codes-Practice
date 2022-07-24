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

    void pathSumH(TreeNode* root, int targetSum, vector<vector<int>> &res, vector<int> ans){
        if (!root) return;
        ans.push_back(root->val);
        pathSumH(root->left,targetSum-root->val,res,ans);
        pathSumH(root->right,targetSum-root->val,res,ans);
        if (!root->left && !root->right && root->val == targetSum)
        {
            res.push_back(ans);
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> ans;

        pathSumH(root,targetSum, res, ans);
        return res;
    }
};