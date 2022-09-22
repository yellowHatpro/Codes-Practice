#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//Left view done using queue, Right done in Leetcode using Reverse Preorder Traversal(using a vector to store the rightmost value, and maintaining a count for each level)
vector<int> leftView(Node *root)
{
   vector<int> res;
   if (!root) return res;
   queue<Node*> q;
   q.push(root);
   while(!q.empty()){
   	int n = q.size();
   	for (int i = 0; i < n; ++i)
   	{
   		if (i==0){
   			res.push_back(q.front()->data);
   		}
   		Node* front = q.front();
   		q.pop();
   		if(front->left) q.push(front->left);
   		if(front->right) q.push(front->right);
   	}
   }
   return res;
}
