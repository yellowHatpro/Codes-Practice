#include <bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
};

class Solution {
  public:
    vector <int> bottomView(Node *root) {
      if (!root) return {};
      map<int,int> m;
      vector<int> res;
      queue<pair<Node*, int>> q;
      q.push({root,0});
      while(!q.empty()){
          Node* curr = q.front().first;
          int coordinate = q.front().second;
          q.pop();
          m[coordinate] = curr->data;
          if (curr->left) q.push({curr->left,coordinate-1});
          if (curr->right) q.push({curr->right,coordinate+1});
      }
      for(auto it: m){
        res.push_back(it.second);
    }
    return res;
    }
};
