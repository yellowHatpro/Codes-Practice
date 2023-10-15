#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

class Solution {
public:
  vector<int> topView(Node *root) {
    if (!root)
      return {};
    vector<int> res;
    map<int, int> m;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
      Node *curr = q.front().first;
      int coordinate = q.front().second;
      q.pop();
      if (m.find(coordinate) == m.end()) {
        m[coordinate] = curr->data;
      }
      if (curr->left)
        q.push({curr->left, coordinate - 1});
      if (curr->right)
        q.push({curr->right, coordinate + 1});
    }
    for (auto itr : m) {
      res.push_back(itr.second);
    }
    return res;
  }
};
