#include <bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
 //Recursive
class Solution {
public:
	vector<int> v;
    vector<int> inorderTraversal(TreeNode* root) {
    	if (root!=NULL){	
    	inorderTraversal(root->left);
    	v.push_back(root->val);
    	inorderTraversal(root->right);
    	
    }
    return v;
	}
};   

//Iterative Solution
class SolutionIterative{
public:
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> nodes;
		stack<TreeNode*> todo;
		while (root||!todo.empty()){
			while(root){
				todo.push(root);
				root = root->left;
			}
			root = todo.top();
			todo.pop();
			nodes.push_back(root->val);
			root = root->right;
		}

	}
};