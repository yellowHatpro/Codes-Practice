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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetricH(root->left,root->right);
    }

    bool isSymmetricH(TreeNode* l, TreeNode* r){
    	if (!l || !r) return l==r;
    	if (l->val!=r->val) return false;
    	return isSymmetricH(l->left, r->right) && isSymmetricH(l->right,r->left);
    }
};

//Time Complexity: O(N) since simple traversals
//Space Complexity: O(N) worst for skew trees