#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
class Solution {
public:

    void binaryTreePathsH(TreeNode* root, vector<string> &res,string s){
        if (!root) return;
        s+=to_string(root->val);
        s+="->";
        binaryTreePathsH(root->left,res,s);
        binaryTreePathsH(root->right,res,s);
        if (!root->left && !root->right)
        {
            s.pop_back();
            s.pop_back();
            res.push_back(s);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string s = "";
        binaryTreePathsH(root, res,s);
        return res;
    }
};