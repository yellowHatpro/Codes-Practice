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
//Iterative Solution
class Solution {

public:
    vector<int> v;

    void inorder(TreeNode* root){
        if (root==nullptr) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
        return;
    }

    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(int i =1; i<v.size(); i++){
            if (v[i-1]>=v[i]) return false;
        }
        return true;
    }
};

//Recursive Approach
class SolutionRecursive {
public:
    bool f(TreeNode* root, TreeNode* lower_limit, TreeNode* upper_limit){
        if (!root) return true;
        if (lower_limit && root->val<= lower_limit->val) return false;
        if (upper_limit && root->val>= upper_limit->val) return false;
        return f(root->left, lower_limit, root) && f(root->right, root, upper_limit);
    }

    bool isValidBST(TreeNode* root) {
        return f(root, nullptr, nullptr);
    }
};