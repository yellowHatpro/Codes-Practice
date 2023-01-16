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

    bool f(TreeNode* root,int prev){
        if (!root) return true;
        f()

    }


public:
    bool isValidBST(TreeNode* root) {
    	int prev = INT_MIN;
       return f(root,prev);

    }
};