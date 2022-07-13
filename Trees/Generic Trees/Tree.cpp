#include<bits/stdc++.h>
using namespace std;

// 1. Generic Tree
template <typename T>
class TreeNode{
public:
	//children and their data property
	T data;
	vector<TreeNode<T>*> children;

	//constructor called and data is taken as input
	TreeNode(T data){
		this->data = data;
	}
};

//Supporting Functions

/*
1. Take Input function:
	> Create a root Node and takes its value from user
	> Create a queue and it will contain the remaining TreeNodes whose children we have to take
	> A while loop which loops until the queue is empty
	> Create a Tree node which takes the front of the queue. We will take children for this front element in upcoming steps.
	> Pop the front from queue , we already made a Tree Node out of it , purpose served.
	> Ask for how many children to create for the front TreeNode
	> A while loop till no. of children .
	> Now ask for the value of the TreeNode and make it the children of the Treenode front.
	> Finally push the child element in the queue as well.
*/


TreeNode<int>* takeInput(){
	int rootData; cin>>rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	//now using a queue to take input level wise
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		//ask how many childs are to be made of the current TreeNode:
		cout<<"Enter number of children of"<<front->data<<endl;
		int numChild;cin>>numChild;
		for (int i = 0; i < numChild; i++)
		{
		int childData;cin>>childData;
		TreeNode<int>* child = new TreeNode<int>(childData);
		front->children.push_back(child);
		pendingNodes.push(child);
		}
	}
	return root;
}


/*  

2. Print Tree Level Wise

*/

void printTree(TreeNode<int>* root){
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty()){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout<< front->data<< " : ";
		for (int i = 0; i < front->children.size(); i++)
		{
			cout<<front->children[i]->data<<" ";
			pendingNodes.push(front->children[i]);
		}
		cout<<endl;
	}
}

int main()
{	TreeNode<int>* tree = new TreeNode<int>(1);
	printTree(takeInput());
    cout<<endl;
    return 0;
}