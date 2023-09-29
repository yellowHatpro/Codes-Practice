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
  int height(Node *root) {
    if (!root)
      return 0;
    int l = height(root->left);
    if (l == -1)
      return -1;
    int r = height(root->right);
    if (r == -1)
      return -1;
    if (abs(l - r) > 1)
      return -1;
    return 1 + max(l, r);
  }

  bool isBalanced(Node *root) { return height(root) != -1; }
};
