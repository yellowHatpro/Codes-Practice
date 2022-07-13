#include "Generic_Tree.h"

TreeNode<int>* takeInput(){//Depth First
    int rootData;cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int n;cin>>n;
    for (int i = 0; i < n; ++i) 
    {   TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

TreeNode<int>* takeInputLevelWise(){//breadth first
    //Queue will have those nodes whose children have not been taken yet
    int rootData;
    cin>>rootData;
   TreeNode<int> * root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;//In nodes k children nhi hain abhi ;)
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
    //edge case not base case.
    if (root == NULL) return;
    cout<< root->data <<": ";
    //This for loop isn't part to print tree, its there to print children of each tree node.
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