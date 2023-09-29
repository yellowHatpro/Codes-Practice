#include <bits/stdc++.h>
using namespace std;

template <typename T> class TreeNode {
public:
  T data;
  TreeNode<T> *left;
  TreeNode<T> *right;

  TreeNode(T data) {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

int f(TreeNode<int> *root, int &cnt) {
  if (!root)
    return 0;
  int l = f(root->left, cnt);
  int r = f(root->right, cnt);
  cnt = max(cnt, l + r);
  int greaterDiameter = 1 + max(l, r);
  return greaterDiameter;
}

int diameterOfBinaryTree(TreeNode<int> *root) {
  int cnt = 0;
  f(root, cnt);
  return cnt;
}
