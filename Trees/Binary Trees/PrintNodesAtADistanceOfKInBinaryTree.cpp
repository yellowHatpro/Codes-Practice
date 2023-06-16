#include <bits/stdc++.h>
using namespace std;

void markParentsUsingBFS(TreeNode* root, map<TreeNode*, TreeNode*> &parents){
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode* node = q.front();
		q.pop();
		if (node->left){ 
			parents[node->left] = node;
			q.push(node->left);}
		if (node->right){
			parents[node->right] = node;
			q.push(node->right);
		}
	}
}

void dfs(vector<int> &res,TreeNode* curr, int k, int i, map<TreeNode*,TreeNode*> parents, map<TreeNode*, bool> &visited){
	if (!curr) return;
	if (!visited[curr]){
		if (i==k){
		res.push_back(curr->val);
		return;
	}
	visited[curr] = 1;
	dfs(res,curr->left,k,i+1,parents,visited);
	dfs(res,curr->right,k,i+1,parents,visited);
	dfs(res,parents[curr],k,i+1,parents,visited);
	}
}

vector<int> f(TreeNode* root, TreeNode* target, int k){
	map<TreeNode*, TreeNode*> parents;
	markParentsUsingBFS(root, parents);
	map<TreeNode*, bool> visited;
	vector<int> res;
	dfs(res,target,k,0,parents, visited);
	return res;
}