#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  Node *left, *right;
};

class Solution {
public:
  bool isLeaf(Node *root) { return !root->left && !root->right; }

  void left(vector<int> &v, Node *root) {
    Node *curr = root->left;
    while (curr) {
      if (!isLeaf(curr))
        v.push_back(curr->data);
      if (curr->left)
        curr = curr->left;
      else
        curr = curr->right;
    }
  }

  void leaves(vector<int> &v, Node *root) {
    if (isLeaf(root))
      v.push_back(root->data);
    if (root->left)
      leaves(v, root->left);
    if (root->right)
      leaves(v, root->right);
  }

  void right(vector<int> &v, Node *root) {
    stack<int> s;
    Node *curr = root->right;
    while (curr) {
      if (!isLeaf(curr))
        s.push(curr->data);
      if (curr->right)
        curr = curr->right;
      else
        curr = curr->left;
    }
    while (!s.empty()) {
      v.push_back(s.top());
      s.pop();
    }
  }

  vector<int> boundary(Node *root) {
    if (!root)
      return {};
    vector<int> v;
    if (!isLeaf(root))
      v.push_back(root->data);
    left(v, root);
    leaves(v, root);
    right(v, root);
    return v;
  }
};
