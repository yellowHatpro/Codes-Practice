#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode{
public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
vector<int> bottomView(BinaryTreeNode<int> * root){
	//Init a resulting vector, A map of column and node->value, and A queue of Pair of Node and Column number
	vector<int> res;
	if(!root) return res;
	map<int,int> m;
	queue<pair<BinaryTreeNode<int>*,int>> q;
	//push root and initial column inside queue
	q.push({root,0});
    while(!q.empty()){
    	BinaryTreeNode<int>* node = q.front().first;
    	int column = q.front().second;
    	q.pop();
    	m[column] = node->data;
    	if(node->left) q.push({node->left,column-1});
    	if(node->right) q.push({node->right,column+1});
    }
    for(auto itr:m){
    	res.push_back(itr.second);
    }
    return res;
}
