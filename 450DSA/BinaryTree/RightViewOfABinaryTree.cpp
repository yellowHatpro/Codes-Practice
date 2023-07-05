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

class Solution
{
    public:
    vector<int> rightView(Node *root) {
      vector<int> v;
      queue<Node*> q;
      q.push(root);
      while (!q.empty()) {      
        int n = q.size();
        for (int i = 0; i < n ; i++) {
          auto curr = q.front();
          q.pop();
          if (i == n-1){
            v.push_back(curr->data);
          }
          if (curr->left) q.push(curr->left);
          if (curr->right) q.push(curr->right);
        }
      }
      return v;
    }
};
