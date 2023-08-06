#include <bits/stdc++.h>
using namespace std;
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
    TreeNode* first;
    TreeNode* prev;
    TreeNode* mid;
    TreeNode* last;

    void inorder(TreeNode* root){
      if (!root) return;
      inorder(root->left);
      if (prev && (root->val < prev->val)){
        if (!first){
          first = prev;
          mid = root;
      } else {
        last = root;
      }
    }
    prev = root;
    inorder(root->right);
  }

    void recoverTree(TreeNode* root) {
      first = mid = last = prev = nullptr;
      inorder(root);
      if (first&&last) swap(first->val,last->val);
      else if (first&&mid) swap(first->val,mid->val);
   }
};
