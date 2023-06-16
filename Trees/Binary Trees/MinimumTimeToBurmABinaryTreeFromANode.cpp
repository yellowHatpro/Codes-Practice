#include <bits/stdc++.h>
using namespace std;
TreeNode* markParentsUsingBFS(TreeNode* root, map<TreeNode*, TreeNode*> &parents, int start){
	queue<TreeNode*> q;
	q.push(root);
	TreeNode* target;
	while(!q.empty()){
		TreeNode* node = q.front();
		q.pop();
		if (node->val==start){
			target = node;
		}
		if (node->left){ 
			parents[node->left] = node;
			q.push(node->left);}
		if (node->right){
			parents[node->right] = node;
			q.push(node->right);
		}
	}
	return target;
}

int bfs(TreeNode* target, map<TreeNode*,TreeNode*> parents){
	queue<TreeNode*> q;
	map<TreeNode*, bool> visited;
	q.push(target);
	visited[target] = 1;
	int time = 0;
	while(!q.empty()){
		int n = q.size();
		int fl = 0;
		for(int i = 0; i<n; i++){
		TreeNode* node = q.front();
		q.pop();
		if (!visited[node->left] && node->left){
			fl = 1;
			visited[node->left] = 1;
			q.push(node->left);
		}
		if (!visited[node->right] && node->right){
			fl = 1;
			visited[node->right] = 1;
			q.push(node->right);
		}
		if (!visited[parents[node]] && parents[node]){
			fl = 1;
			visited[parents[node]] = 1;
			q.push(parents[node]);
		}
	}
		if (fl) time++;
	}
	return time;
}

int f(TreeNode* root, int start){
	map<TreeNode*, TreeNode*> parents;
	TreeNode* target = markParentsUsingBFS(root, parents, start);
	return bfs(target, parents);
}