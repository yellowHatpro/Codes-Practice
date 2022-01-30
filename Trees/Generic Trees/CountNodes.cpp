#include "Generic_Tree.h"

int countNode(TreeNode<int>* root){
    int ans = 1;
    if (root==NULL) return 0;
    for(int i =0 ;i<root->children.size();i++){
        ans+=countNode(root->children[i]);
    }
    return ans;
}