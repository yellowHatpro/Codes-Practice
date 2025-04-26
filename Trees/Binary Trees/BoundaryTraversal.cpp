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

bool isLeaf(TreeNode<int> *root) {
  if (!root->left && !root->right)
    return true;
  return false;
}

void addLeftBoundary(vector<int> &res, TreeNode<int> *root) {
  TreeNode<int> *cur = root->left;
  while (cur) {
    if (!isLeaf(cur))
      res.push_back(cur->data);
    if (cur->left)
      cur = cur->left;
    else
      cur = cur->right;
  }
}

void addLeaves(vector<int> &res, TreeNode<int> *root) {
  // inorder traversal
  if (isLeaf(root)) {
    res.push_back(root->data);
  }
  if (root->left)
    addLeaves(res, root->left);
  if (root->right)
    addLeaves(res, root->right);
}

void addRightBoundary(vector<int> &res, TreeNode<int> *root) {
  TreeNode<int> *cur = root->right;
  vector<int> temp;
  while (cur) {
    if (!isLeaf(cur))
      temp.push_back(cur->data);
    if (cur->right)
      cur = cur->right;
    else
      cur = cur->left;
  }
  for (int i = temp.size() - 1; i >= 0; i--) {
    res.push_back(temp[i]);
  }
}

vector<int> printBoundary(TreeNode<int> *root) {
  vector<int> res;
  if (!root)
    return res;
  if (!isLeaf(root))
    res.push_back(root->data);
  addLeftBoundary(res, root);
  addLeaves(res, root);
  addRightBoundary(res, root);
  return res;
}

void addLeavesToRes(TreeNode<int> *root, vector<int> &v) {
  if (root) {
    addLeavesToRes(root->left, v);
    if (!root->left && !root->right) {
      v.push_back(root->data);
    }
    addLeavesToRes(root->right, v);
  }
}

vector<int> traverseBoundary(TreeNode<int> *root) {
  vector<int> res;
  if (!root)
    return {};
  if (!root->left && !root->right) {
    return {root->data};
  }
  res.push_back(root->data);
  // traverse left side
  TreeNode<int> *leftTemp = root->left;
  while (leftTemp) {
    if (!leftTemp->left && !leftTemp->right) {
      break;
    }
    res.push_back(leftTemp->data);
    if (leftTemp->left) {
      leftTemp = leftTemp->left;
    } else {
      leftTemp = leftTemp->right;
    }
  }
  // add leaves
  TreeNode<int> *leafTemp = root;
  TreeNode<int> *rightTemp = root->right;
  addLeavesToRes(leafTemp, res);
  stack<int> s;
  while (rightTemp) {
    if (!rightTemp->left && !rightTemp->right) {
      break;
    }
    s.push(rightTemp->data);
    if (rightTemp->right) {
      rightTemp = rightTemp->right;
    } else {
      rightTemp = rightTemp->left;
    }
  }
  while (!s.empty()) {
    int stop = s.top();
    res.push_back(stop);
    s.pop();
  }
  return res;
}
