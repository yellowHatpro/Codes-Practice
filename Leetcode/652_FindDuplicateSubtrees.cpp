#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
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

	string dfs(TreeNode* root, map<string, int> &m, vector<TreeNode*> &ans){
		if (!root) return "";
		string str =  to_string(root->val) + "," + dfs(root->left, m, ans) + "," + dfs(root->right, m, ans);
		m[str]++;
		if (m[str]==2){
			ans.push_back(root);
		}
		return str;
	}

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string, int> m;
        vector<TreeNode*> res;
        dfs(root, m, res);
        return res;
    }
};