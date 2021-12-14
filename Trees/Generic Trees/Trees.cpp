#include "Generic_Tree.h"

TreeNode<int>* takeInputLevelWise(){
    //Queue will have those nodes whose children have not been taken yet
    int rootData;
    cin>>rootData;
   TreeNode<int> * root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin>>numChild;
        for(int i = 0 ; i<numChild;i++){
            int childData;
            cin>>childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;

}

void printTree(TreeNode<int>* root){
    if (root == NULL) return;
    cout<< root->data <<": ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}
int main(){
    TreeNode<int>* root1 = new TreeNode<int>(1);
    TreeNode<int>* child1 = new TreeNode<int>(2);
    TreeNode<int>* child2 = new TreeNode<int>(3);
    // root->children.push_back(child1);
    // root->children.push_back(child2);
    TreeNode<int>*root = takeInputLevelWise();
    printTree(root);


}