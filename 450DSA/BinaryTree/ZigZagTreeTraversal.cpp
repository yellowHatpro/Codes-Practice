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

class Solution {
public:
  vector<int> zigZagTraversal(Node *root) {
    vector<int> res;
    bool rev = 0;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      vector<int> currRow(n);
      for (int i = 0; i < n; i++) {
        auto curr = q.front();
        q.pop();
        if (rev) {
          currRow[n - 1 - i] = curr->data;
        } else {
          currRow[i] = curr->data;
        }
        if (curr->left)
          q.push(curr->left);
        if (curr->right)
          q.push(curr->right);
      }
      rev = !rev;
      res.insert(res.end(), currRow.begin(), currRow.end());
    }
    return res;
  }
};
