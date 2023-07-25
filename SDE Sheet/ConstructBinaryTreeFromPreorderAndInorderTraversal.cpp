#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


class Solution {
public:

    TreeNode* f(map<int,int> &inMap, vector<int>&pre, int pi, int pj, vector<int>& in, int ii, int ij ){
    if (pi>pj || ii > ij) return nullptr;
    TreeNode* root = new TreeNode(pre[pi]);
    int inRootIdx = inMap[pre[pi]];
    int leftRangeInorder = inRootIdx - ii;
    root->left = f(inMap, pre, pi+1,pi+leftRangeInorder,in, ii,inRootIdx-1);
    root->right = f(inMap, pre,pi+leftRangeInorder+1, pj, in, inRootIdx+1,ij);
    return root;
  }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      map<int,int> inMap;
      int n = inorder.size();
      for(int i = 0; i < n; i++){
        inMap[inorder[i]] = i;
      }
      return f(inMap, preorder, 0, n-1, inorder, 0, n-1);
    }
};
