#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int cnt = 0;
	void f(TreeNode* root, bool l, int ct){
		if (!root) return ;
		cnt = max(cnt,ct);
		if (l){
			f(root->left,0,ct+1);
			f(root->right,1,1);
		} else {
			f(root->right,1,ct+1);
			f(root->left,0,1);
		}
	}

    int longestZigZag(TreeNode* root) {
        f(root,1,0);
				f(root,0,0);
				return cnt;
    }
};