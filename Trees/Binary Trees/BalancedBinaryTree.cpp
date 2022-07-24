#include "BinaryTree.h"


//Balanced Binary Tree  -> for every node: abs(height(left subtree)-height(right subtree)) <=1


//Check if Balanced Binary Tree


int height(BinaryTreeNode<int>* root){
	if (!root) return 0;
	return 1 + max(height(root->left), height(root->right));
}


bool isBalancedBinaryTree(BinaryTreeNode<int>* root){
	if (!root) return true;
	if (abs(height(root->left)-height(root->right))>1)
	{
		return false;
	}
	bool c1 = isBalancedBinaryTree(root->left);
	bool c2 = isBalancedBinaryTree(root->right);
	if (c1 && c2){
		return true;
	} else return false;
	
}