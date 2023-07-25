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
  
    TreeNode* f(map<int,int>& inMap, vector<int>& in, int ii, int ij, vector<int>& post, int pi, int pj){
    if (ii>ij || pi>pj) return nullptr;
    TreeNode* root = new TreeNode(post[pj]);
    int rootIndexInorder = inMap[post[pj]];
    int leftRangeInorder = rootIndexInorder-ii;
    root->left = f(inMap,in, ii, rootIndexInorder-1,post,pi, pi+leftRangeInorder-1);
    root->right= f(inMap, in, rootIndexInorder+1, ij, post, pi+leftRangeInorder,pj-1);
    return root;
  }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      int n = inorder.size();
      map<int,int> inMap;
      for(int i = 0; i < n; i++){
        inMap[inorder[i]] = i;  
      }
      return f(inMap,inorder,0,n-1, postorder, 0, n-1);
    }
};
