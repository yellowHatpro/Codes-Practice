#include "BinaryTree.h"

bool isNodePresent(BinaryTreeNode<int>* root, int x){
	if (root==nullptr)
	{
		return false;
	}
	if (root->data==x)
	{
		return true;
	}
	bool c1 = isNodePresent(root->left, x);
	bool c2 = isNodePresent(root->right,x);

	return c1 || c2;
}