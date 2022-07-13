#include <bits/stdc++.h>
#include "Generic_Tree.h"
using namespace std;

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
	TreeNode<int>* res = root;
	if (root == nullptr)
	{
		return root;
	}
	for (int i = 0; i < root->children.size(); ++i)
	{	
		TreeNode<int>* c = maxDataNode(root->children[i]);
		if (res->data<c->data)
		{
			res=c;
		}
	}
	return res;
}