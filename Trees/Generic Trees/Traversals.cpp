#include "Generic_Tree.h"
void preorder(TreeNode<int>* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int>* root){
    if (root==NULL) return;
    for(int i=0;i<root->children.size();i++){
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}