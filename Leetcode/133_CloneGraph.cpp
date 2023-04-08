#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:

	Node* bfs(Node* root){
		queue<Node*> q;
		map<Node*,Node*> copy;
		q.push(root);
		Node* res = new Node(root->val);
		copy[root] = res;
		while(!q.empty()){
			Node* newNode = q.front();
			q.pop();
			for(auto itr: newNode->neighbors){
				if (copy.find(itr)==copy.end()){
					copy[itr] = new Node(itr->val);
					q.push(itr);
				}
				copy[newNode]->neighbors.push_back(copy[itr]);
			}
		}
		return res;
	}

    Node* cloneGraph(Node* node) {
    	if (!node) return node;
        return bfs(node);
    }
};