#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *targetTreeNode;

  void markParentsUsingDFS(TreeNode *root, map<TreeNode *, TreeNode *> &parents,
                           int start) {
    if (!root) {
      return;
    }
    if (root->val == start) {
      targetTreeNode = root;
    }
    if (root->left) {
      parents[root->left] = root;
      markParentsUsingDFS(root->left, parents, start);
    }
    if (root->right) {
      parents[root->right] = root;
      markParentsUsingDFS(root->right, parents, start);
    }
  }

  TreeNode *markParentsUsingBFS(TreeNode *root,
                                map<TreeNode *, TreeNode *> &parents,
                                int start) {
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *target;
    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();
      if (node->val == start) {
        target = node;
      }
      if (node->left) {
        parents[node->left] = node;
        q.push(node->left);
      }
      if (node->right) {
        parents[node->right] = node;
        q.push(node->right);
      }
    }
    return target;
  }

  int bfs(TreeNode *target, map<TreeNode *, TreeNode *> parents) {
    queue<TreeNode *> q;
    map<TreeNode *, bool> visited;
    q.push(target);
    visited[target] = 1;
    int time = 0;
    while (!q.empty()) {
      int n = q.size();
      int fl = 0;
      for (int i = 0; i < n; i++) {
        TreeNode *node = q.front();
        q.pop();
        if (!visited[node->left] && node->left) {
          fl = 1;
          visited[node->left] = 1;
          q.push(node->left);
        }
        if (!visited[node->right] && node->right) {
          fl = 1;
          visited[node->right] = 1;
          q.push(node->right);
        }
        if (!visited[parents[node]] && parents[node]) {
          fl = 1;
          visited[parents[node]] = 1;
          q.push(parents[node]);
        }
      }
      if (fl)
        time++;
    }
    return time;
  }

  int amountOfTime(TreeNode *root, int start) {
    map<TreeNode *, TreeNode *> parents;
    // TreeNode *target = markParentsUsingBFS(root, parents, start);
    markParentsUsingDFS(root, parents, start);
    return bfs(targetTreeNode, parents);
  }
};
