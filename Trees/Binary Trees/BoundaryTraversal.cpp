#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode {
   public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

bool isLeaf(TreeNode<int>* root){
	if(!root->left && !root->right) return true;
	return false;
}

void addLeftBoundary(vector<int> &res, TreeNode<int>* root){
TreeNode<int>* cur = root->left;
while(cur){
	if (!isLeaf(cur)) res.push_back(cur->val);
	if(cur->left) cur = cur->left;
	else cur = cur->right;
}
}

void addLeaves(vector<int> & res, TreeNode<int>* root){
	//inorder traversal
	if(isLeaf(root)){
		res.push_back(root->val);
	}
	if(root->left) addLeaves(res,root->left);
	if(root->right) addLeaves(res,root->right);
}

void addRightBoundary(vector<int> &res, TreeNode<int>* root){
	TreeNode<int>* cur = root->right;
	vector<int> temp;
	while(cur){
		if(!isLeaf(cur)) temp.push_back(cur->val);
		if(cur->right) cur = cur->right;
		else cur = cur->left;
	}
	for(int i = temp.size()-1; i>=0;i--){
		res.push_back(temp[i]);
	}
}


vector<int> printBoundary(TreeNode<int>* root){
	vector<int> res;
	if (!root) return res;
	if (!isLeaf(root)) res.push_back(root->val);
	addLeftBoundary(res,root);
	addLeaves(res,root);
	addRightBoundary(res,root);
	return res;
}