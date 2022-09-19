#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int f(TreeNode<int>* root, int& maxi){
	if (!root) return 0;
	int c1 = max(f(root->left,maxi),0);
	int c2 = max(f(root->right, maxi),0);
	maxi = max(maxi,root->val+c1+c2);
	return root->val + max(c1,c2);


}

int maxPathSum(TreeNode<int>* root)
{
	int maxi = INT_MIN;
	f(root,maxi);
	return maxi;
}