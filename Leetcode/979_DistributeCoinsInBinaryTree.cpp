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
    int f(TreeNode* root, int&ans){
      if (!root) return 0;
      int a = f(root->left,ans);
      int b = f(root->right,ans);
      ans += abs(a) + abs(b);
      return root->val + a + b -1;
  }
    int distributeCoins(TreeNode* root) {
    int ans = 0;
      f(root,ans);
      return ans;
    }
};
