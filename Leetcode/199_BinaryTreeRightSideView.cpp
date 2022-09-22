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

	void f(TreeNode* root, int lvl, vector<int>&v){
		if (!root) return ;
		if(v.size()==lvl)   v.push_back(root->val);
		if(root->right) f(root->right, lvl+1,v);
		if(root->left) f(root->left, lvl+1,v);
	}

    vector<int> rightSideView(TreeNode* root) {
    	vector<int> v;
        f(root,0,v);
        return v;
    }
};