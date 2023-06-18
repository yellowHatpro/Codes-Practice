#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	TreeNode prev = NULL;

    void flatten(TreeNode* root) {
        //Using morris traversal
        TreeNode* curr = root;
        while(curr){
        	if (curr->left){
        		TreeNode* prev = curr->left;
        		while(prev->right){
        			prev = prev->right;
        		}
        		prev->right = curr->right;
        		curr->right = curr->left;
        	}
        	curr = curr->right;
        }
    }

    void flattenRecursive(TreeNode* root){
    	if (!root) return;
    	flatten(node->right);
    	flatten(node->left);
    	node->right = prev;
    	node->left = NULL;
    	prev = node;
    }
};