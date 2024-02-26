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

  ~TreeNode() {
    if (left)
      delete left;
    if (right)
      delete right;
  }
};

bool isLeaf(TreeNode<int> *node) { return !node->left and !node->right; }

void addToLeaves(vector<int> &leaves, TreeNode<int> *root) {
  if (!root)
    return;
  addToLeaves(leaves, root->left);
  if (isLeaf(root))
    leaves.push_back(root->data);
  addToLeaves(leaves, root->right);
}

vector<int> traverseBoundary(TreeNode<int> *root) {
  vector<int> leftBoundary;
  vector<int> leaves;
  vector<int> rightBoundary;
  // left boundary
  TreeNode<int> *temp = root;
  while (!isLeaf(temp)) {
    leftBoundary.push_back(temp->data);
    if (temp->left) {
      temp = temp->left;
    } else
      temp = temp->right;
  }
  temp = root;
  // Leaves
  addToLeaves(leaves, temp);
  temp = root;
  // Right boundary
  while (!isLeaf(temp)) {
    rightBoundary.push_back(temp->data);
    if (temp->right) {
      temp = temp->right;
    } else
      temp = temp->left;
  }
  reverse(begin(rightBoundary), end(rightBoundary));
  vector<int> res;
  res.insert(res.end(), leftBoundary.begin(), leftBoundary.end());
  res.insert(res.end(), leaves.begin(), leaves.end());
  res.insert(res.end(), rightBoundary.begin(), rightBoundary.end());
  return res;
}
