#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int f = 1;
	int solve(TreeNode* node) {
		if (!node)
		{
			return 0;
		}
		int lh = solve(node->left);
		int rh = solve(node->right);

		if (abs(lh-rh)>1)
		{
			f=0;
		}
		return 1+max(lh,rh);
	}
	bool isBalanced(TreeNode* root){
		f=1;
		solve(root);
		return f;
	}
};