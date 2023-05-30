#include "BinaryTree.h"

//Diameter = Longest path between 2 nodes
//Path does not need to pass via root

//The diamater is stored in cnt
int diameterOfBinaryTreeHelper(BinaryTreeNode<int>* root, int cnt){
	if (!root) return 0;
	int c1 = diameterOfBinaryTreeHelper(root->left,cnt);
	int c2 = diameterOfBinaryTreeHelper(root->right, cnt);
	int greaterHeight = 1 + max(c1,c2);
	cnt = max(cnt, c1+c2);
	return greaterHeight;
}	
int diameterOfBinaryTree(BinaryTreeNode<int>* root){
	int cnt = 0;
	return diameterOfBinaryTreeHelper(root, cnt);
}
