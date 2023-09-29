#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *left;
  struct Node *right;

  Node(int x) {
    data = x;
    left = right = NULL;
  }
};

class Solution {
public:
  // Function to return the level order traversal of a tree.
  vector<int> levelOrder(Node *node) {
    if (!node)
      return {};
    vector<int> ans;
    queue<Node *> q;
    q.push(node);
    while (!q.empty()) {
      auto curr = q.front();
      q.pop();
      ans.push_back(curr->data);
      if (curr->left)
        q.push(curr->left);
      if (curr->right)
        q.push(curr->right);
    }
    return ans;
  }
};
