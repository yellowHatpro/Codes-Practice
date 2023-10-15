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
  TreeNode *builder(vector<int> &pre, vector<int> &in, int pl, int pr, int il,
                    int ir, map<int, int> &inMap) {
    if (pl > pr || il > ir)
      return NULL;
    TreeNode *root = new TreeNode(pre[pl]);
    int inRoot = inMap[root->val];
    int range = inRoot - il;
    root->left = builder(pre, in, pl + 1, pl + range, il, inRoot - 1, inMap);
    root->right = builder(pre, in, pl + 1 + range, pr, inRoot + 1, ir, inMap);
    return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();
    map<int, int> inMap;
    for (int i = 0; i < inorder.size(); ++i) {
      inMap[inorder[i]] = i;
    }
    return builder(preorder, inorder, 0, n - 1, 0, n - 1, inMap);
  }
};
