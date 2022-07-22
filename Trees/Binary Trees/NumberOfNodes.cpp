#include "BinaryTree.h"

int numberOfNodes(BinaryTreeNode<int>* root){
	if (root == nullptr)
	{
		return 0;
	}
	int cnt = 1;
	int left = numberOfNodes(root->left);
	int right = numberOfNodes(root->right);
	return 1+left+right;
}