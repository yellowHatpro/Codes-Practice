#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

class Solution {
public:
  vector<int> bottomView(Node *root) {
    vector<int> res;
    if (!root)
      return res;
    map<int, int> m;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
      auto it = q.front();
      q.pop();
      m[it.second] = it.first->data;
      if (it.first->left)
        q.push({it.first->left, it.second - 1});
      if (it.first->right)
        q.push({it.first->right, it.second + 1});
    }
    for (auto it : m) {
      res.push_back(it.second);
    }
    return res;
  }
};
