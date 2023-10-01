#include <bits/stdc++.h>
using namespace std;

TreeNode *builder(vector<int> &preorder, int preStart, int preEnd,
                  vector<int> &inorder, int inStart, int inEnd,
                  map<int, int> inMap) {
  if (preStart > preEnd || inStart > inEnd)
    return nullptr;
  TreeNode *root = new TreeNode(preorder[preStart]);
  int inRoot = inMap[root->val]; // position of root in inorder vector
  int range = inRoot - inStart;
  root->left = builder(preorder, preStart + 1, preStart + range, inorder,
                       inStart, inRoot - 1, inMap);
  root->right = builder(preorder, preStart + 1 + range, preEnd, inorder,
                        inRoot + 1, inEnd, inMap);
  return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
  map<int, int> inMap;
  for (int i = 0; i < inorder.size(); ++i) {
    inMap[inorder[i]] = i;
  }
  TreeNode *root = builder(preorder, 0, preorder.size() - 1, inorder, 0,
                           inorder.size() - 1, inMap);
  return root;
}
