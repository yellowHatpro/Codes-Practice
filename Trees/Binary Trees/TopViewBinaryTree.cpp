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

vector<int> topView(TreeNode<int> *root) {
  vector<int> res;
  if (!root)
    return res;
  map<int, int> m;
  queue<pair<TreeNode<int> *, int>> q;
  q.push({root, 0});
  while (!q.empty()) {
    auto it = q.front();
    q.pop();
    // if map has already has the value ignore those values
    if (m.find(it.second) == m.end()) {
      m[it.second] = it.first->val;
    }
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
