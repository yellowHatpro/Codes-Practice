#include <bits/stdc++.h>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode* A) {
	stack<TreeNode*> s;
	vector<int> v;
	s.push(A);
	while(!s.empty()){
		TreeNode* t = s.top();
		v.push_back(s.top()->val);
		s.pop();
		if (t->right)s.push(t->right);
		if (t->left)s.push(t->left);
	}
	return v;
}

