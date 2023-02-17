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

    int d1 = INT_MAX;
    int res = INT_MAX;
    void inorder(TreeNode* root){
        if (!root) return;
        if (root->left) inorder(root->left);
        if (d1!=INT_MAX){
            res = min(res,root->val - d1);
        }
        d1 = root->val;
        if(root->right) inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return res;
    }
};