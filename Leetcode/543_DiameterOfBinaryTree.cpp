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
    int diameterOfBinaryTreeHelper(TreeNode* root, int &cnt){
	if (!root) return 0;
	int c1 = diameterOfBinaryTreeHelper(root->left,cnt);
	int c2 = diameterOfBinaryTreeHelper(root->right, cnt);
	int greaterHeight = 1 + max(c1,c2);
	cnt = max(cnt,c2+c1);
	return greaterHeight;
}	
    int diameterOfBinaryTree(TreeNode* root) {
        int cnt = 0;
         diameterOfBinaryTreeHelper(root, cnt) ;
        return cnt;
    }
};