#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
public:

	bool isLeaf(Node* root){
		if (!root->left && !root->right) return true;
		else return false;
	}
	void boundaryNodes(vector<int>& res, Node* root){
		if (isLeaf(root)){
			res.push_back(root->data);
		}
	if(root->left) 	boundaryNodes(res,root->left);
	if(root->right)	boundaryNodes(res,root->right);
	}


	void left(vector<int>& res, Node* root){
   	Node* cur = root->left;
    while(cur){
    	if (!isLeaf(cur)) res.push_back(cur->data);
    	if(cur->left) cur = cur->left;
    	else cur = cur->right;
}
	}

	void right(vector<int>& res, Node* root){
		if (!root || isLeaf(root)){
			return;
		}
		if (root->right) right(res,root->right);
		else (right(res,root->left));
		res.push_back(root->data);

	}

    vector <int> boundary(Node *root)
    {	vector<int> res;
    	if (!root) return res; 
    	if (!isLeaf(root))res.push_back(root->data);
        left(res,root);
        boundaryNodes(res,root);
        right(res,root->right);
    }
};