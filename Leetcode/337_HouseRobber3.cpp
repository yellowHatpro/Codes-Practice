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

    int f(map<TreeNode*,int> &m, TreeNode* node){
    if (!node) return 0;
    if (m.find(node)!=m.end()) return m[node];
    
    int take = node->val;
    if (node->left) take+=f(m,node->left->left) + f(m,node->left->right);
    if (node->right) take+=f(m,node->right->left) + f(m,node->right->right);
    int notTake = f(m,node->left) + f(m,node->right);
    return m[node] = max(take,notTake);
  }

    int rob(TreeNode* root) {
      map<TreeNode*,int> m;
      return f(m,root);
    }
};
