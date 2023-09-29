#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

vector<int> reverseLevelOrder(Node *root) {
  stack<vector<int>> s;
  vector<int> v;
  queue<Node *> q;
  q.push(root);
  while (!q.empty()) {
    int n = q.size();
    vector<int> currRow;
    for (int i = 0; i < n; i++) {
      auto node = q.front();
      q.pop();
      currRow.push_back(node->data);
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    s.push(currRow);
  }
  while (!s.empty()) {
    auto stop = s.top();
    for (auto itr : stop) {
      v.push_back(itr);
    }
    s.pop();
  }
  return v;
}
