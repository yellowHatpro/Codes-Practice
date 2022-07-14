#include <bits/stdc++.h>
using namespace std;
int getLeafNodeCount(TreeNode<int>* root) {
	if (!root)
	{
		return 0;
	}
	if (root->children.size()==0)
	{
		return 1;
	}
	int cnt= 0;
	for (int i = 0; i < root->children.size(); ++i)
	{
		cnt+=getLeafNodeCount(root->children[i]);
	}
	return cnt;
}