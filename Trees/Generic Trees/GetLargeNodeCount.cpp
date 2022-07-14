#include "Generic_Tree.h"

int getLargeNodeCount(TreeNode<int>* root, int x) {
	int cnt = 0;
	if (!root)
	{
		return 0;
	}

	for (int i = 0; i < root->children.size(); ++i)
	{
		cnt=getLargeNodeCount(root->children[i],x);
	}
	if (root->data>x)
	{
		cnt++;
	}
	return cnt;


}