#include <bits/stdc++.h>
using namespace std;

	template <typename T>
    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


void changeTree(BinaryTreeNode < int > * root) {
	if(!root) return;
	int childSum = 0;
	if (root->left) childSum+=root->left->data;
	if (root->right) childSum+=root->right->data;
	if (childSum>=root->data) {
		root->data = childSum;
	} else {
		if (root->left) root->left->data = root->data;
		if (root->right) root->right->data = root->data;
	}

    changeTree(root->left);
    changeTree(root->right);
    int rootSumTODO = 0;
    if(root->left) rootSumTODO+=root->left->data;
    if (root->right) rootSumTODO+=root->right->data;
    if (root->left || root->right) root->data = rootSumTODO;
    return;
}  