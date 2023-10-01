#include <bits/stdc++.h>
using namespace std;

template <typename T> class TreeNode {
public:
  T val;
  TreeNode<T> *left;
  TreeNode<T> *right;

  TreeNode(T val) {
    this->val = val;
    left = NULL;
    right = NULL;
  }
};

vector<vector<int>> zigZagTraversal(TreeNode<int> *root) {
  vector<vector<int>> res;
  if (!root)
    return res;
  queue<TreeNode<int> *> pendingNodes;
  pendingNodes.push(root);
  bool flag = true; // 0 means its right to left
  while (!pendingNodes.empty()) {
    int n = pendingNodes.size();
    vector<int> row(n);
    for (int i = 0; i < n; ++i) {
      TreeNode<int> *node = pendingNodes.front();
      pendingNodes.pop();
      int index = (flag) ? i : (n - i - 1);
      row[index] = node->val;
      if (node->left)
        pendingNodes.push(node->left);
      if (node->right)
        pendingNodes.push(node->right);
    }
    flag = !flag;
    res.push_back(row);
  }
  return res;
}
