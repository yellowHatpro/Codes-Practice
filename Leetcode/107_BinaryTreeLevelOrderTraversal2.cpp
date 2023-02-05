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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        stack<vector<int>> s;
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
        	int n = q.size();
        	vector<int> v;
        	for (int i = 0; i < n; ++i)
        	{
        		TreeNode* newNode = q.front();
        		q.pop();
        		v.push_back(newNode->val);
        		if (newNode->left) q.push(newNode->left);
        		if (newNode->right) q.push(newNode->right);
        	}
        	s.push(v);
        }
        while(!s.empty()){
        	res.push_back(s.top());
        	s.pop();
        }
        return res;
    }
};