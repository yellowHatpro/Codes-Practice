#include "BinaryTree.h"

BinaryTreeNode<int>* takeInput(){
    int data ;cin>>data;
    if(data==-1) return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
    BinaryTreeNode<int>* left = takeInput();
    BinaryTreeNode<int>* right = takeInput();
    root->left = left;
    root->right = right;
    return root;
}

void printBT(BinaryTreeNode<int>* root){
    if(root == NULL) return;
    cout<<root->data<<": ";
    if(root->left!=NULL)
        cout<<"L "<<root->left->data<<" ";

    if(root->right!=NULL)    
        cout<<"R "<<root->right->data<<" ";
    cout<<endl;
    printBT(root->left);
    printBT(root->right);
}

int main(){
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    root->left = node1;
    root->right = node2;
    printBT(root);
    delete root;
}