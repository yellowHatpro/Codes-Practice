#include "Generic_Tree.h"


class Pair{
public:
	int currentSum;
	TreeNode<int>* node;
	Pair(int data, TreeNode<int>* node){
		this->currentSum = data;
		this->node = node;
	}
};

int countNodeSum(TreeNode<int>* head){
	if (head==nullptr)
	{
		return 0;
	}
	int cnt=head->data;
	for (int i = 0; i < head->children.size(); ++i)
	{
		cnt+=head->children[i]->data;
	}
	return cnt;
}

Pair* maxSumNodeHelper(Pair* pair){
	int maxSum = pair->currentSum;
	TreeNode<int>* maxi = pair->node;
	if (pair->node==nullptr)
	{
		return NULL;
	}
	for (int i = 0; i < pair->node->children.size(); ++i)
	{	Pair* checkerPair = new Pair(countNodeSum(pair->node->children[i]),pair->node->children[i]);
		Pair* secPair = maxSumNodeHelper(checkerPair);
		if (secPair->currentSum>maxSum)
		 {
		 	maxi = secPair->node;
		 	maxSum = secPair->currentSum;
		 } 
	}
		Pair* maxPair = new Pair(maxSum,maxi);
	return maxPair;
}

TreeNode<int>* maxSumNode(TreeNode<int> *root){
	Pair* pair = new Pair (countNodeSum(root),root);
	return maxSumNodeHelper(pair)->node;

}