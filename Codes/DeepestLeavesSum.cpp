#include <bits/stdc++.h>
using namespace std;
template <typename T>
    class TreeNode 
    {
        public : 
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    void helper(TreeNode<int>* root , int &count , int level , int &maxlevel){
    	if (root==NULL){
		return ;
	}
	
	if (root->left==NULL && root->right == NULL){
		if (level>maxlevel){
			count=root->data;
			maxlevel = level;

		}
		else if (level==maxlevel){
		count+=root->data;
	}
	}
	if (root->left!=NULL){
			helper(root->left,count ,level+1, maxlevel);

	}
	if (root->right !=NULL){
		helper(root->right,count,level+1, maxlevel);
	}
    }
    int deepestLeavesSum(TreeNode<int>* root)
{	int count=0;
	int maxlevel = 0;
	helper(root , count ,0,maxlevel);
	return count;

}

int main(){

cout<<endl;
	return 0;
}