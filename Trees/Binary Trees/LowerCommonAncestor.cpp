#include "BinaryTree.h"
/*The common ancestor that exists at the deepest level
					   1
					/    \
				   2      3
				 / \     / \
				4   5   8   9

LCA(4,2) = 2
LCA(3,4) = 1
*/

    BinaryTreeNode<int>* lowestCommonAncestor(BinaryTreeNode<int>* root, BinaryTreeNode<int>* p, BinaryTreeNode<int>* q) {
        if (!root || root==p || root==q) return root;
        BinaryTreeNode<int>* a = lowestCommonAncestor(root->left,p,q);
     	BinaryTreeNode<int>* b = lowestCommonAncestor(root->right,p,q);

       if (!a)
       {
       	return b;
       }
       else if (!b){
       	return a;
       }
       else {
       	return root;
       }
    }
