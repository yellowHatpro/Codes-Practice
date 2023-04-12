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

	TreeNode* tree(vector<int> & pro, vector<int>& ino, int lp, int rp, int li, int ri){
		if (li==ri+1) return nullptr;
		if (li==ri) 
	}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return tree(preorder, inorder, 0,n-1,0,n-1);
    }
};