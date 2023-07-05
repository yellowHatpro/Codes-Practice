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

vector<int> leftView(Node *root) {
  vector<int> v;
  if (!root) return {};
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    int n = q.size();
    bool gotOne = 0;
    for(int i = 0 ; i < n; i++){
      auto curr = q.front();
      q.pop();
      if (gotOne==0) {
        v.push_back(curr->data);
        gotOne = 1;
        }
      if (curr->left) q.push(curr->left);
      if (curr->right) q.push(curr->right);
    }
  }
  return v;
}
