#include <bits/stdc++.h>
using namespace std;



struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	queue<Node*> q;
    	q.push(root);
    	bool flag = 1;
    	vector<int> res;
    	while(!q.empty()){
    		int n = q.size();
    		vector<int> v2(n);
    		if (flag){
    			for (int i = 0; i < n; ++i)
    			{
    				Node* a = q.front();
    				q.pop();
    				v2[i] = a->data;
    				if(a->left)q.push(a->left);
    				if(a->right)q.push(a->right);
    			}
    		} else {
    			for(int i = n-1;i>=0;i--){
    				Node* a = q.front();
    				q.pop();
    				v2[i] = a->data;
    				if(a->left)q.push(a->left);
    				if(a->right)q.push(a->right);
    			}
    		}
    		flag = !flag;
    		copy(v2.begin(), v2.end(), back_inserter(res));
    	}
        return res;
    }
};


int main(){
	
	return 0;
}