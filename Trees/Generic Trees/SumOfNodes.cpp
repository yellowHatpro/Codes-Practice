#include <bits/stdc++.h>
#include "Generic_Tree.h"
using namespace std;

int sumOfNodes(TreeNode<int>* root) {
	if (root==NULL)
	{
		return 0;
	}
	int sum=root->data;
	for (int i = 0; i < root->children.size(); ++i)
	{
		sum+=sumOfNodes(root->children[i]); 
	}
	return sum;

}