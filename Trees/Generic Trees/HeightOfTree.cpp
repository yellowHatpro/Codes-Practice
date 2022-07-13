#include <bits/stdc++.h>
#include "Generic_Tree.h"
using namespace std;
int getHeight(TreeNode<int>* root) {
	int h = 0;
	if (root==NULL)
	{
		return 0;
	}
	for (int i = 0; i < root->children.size(); ++i)
	{
		int res = getHeight(root->children[i]);
		if (res>h)
		{
			h=res;
		}
	}
	return 1+h;
}