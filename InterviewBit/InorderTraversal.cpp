#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for binary tree
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* A) {
	vector<int> v;
if (!A) return v;
vector<int> a = inorderTraversal(A->left);
copy(a.begin(), a.end(), back_inserter(v));
v.push_back(A->val);
vector<int> b = inorderTraversal(A->right);
copy(b.begin(), b.end(), back_inserter(v));
return v;
}
