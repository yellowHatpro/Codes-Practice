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

struct TreeNodeHelper {
    int minVal;
    int maxVal;
    int sum;
    int maxSum;
    TreeNodeHelper(int minVal, int maxVal, int sum, int maxSum) : 
    minVal(minVal), maxVal(maxVal), sum(sum), maxSum(maxSum) {} 
  };

class Solution {
public:
  
    TreeNodeHelper f(TreeNode* root){
      if (!root) return TreeNodeHelper(INT_MAX, INT_MIN, 0,0);
      auto left = f(root->left);
      auto right = f(root->right);
      if (left.maxVal < root->val && root->val < right.minVal) {
        int _sum = root->val+left.sum+right.sum;
        int _maxSum = max(max(left.maxSum,right.maxSum),_sum);
        return TreeNodeHelper(min(root->val, left.minVal), max(root->val,right.maxVal),_sum,_maxSum); 
      }
      return TreeNodeHelper(INT_MIN, INT_MAX, max(left.sum,right.sum), max(left.maxSum,right.maxSum));
    }

    int maxSumBST(TreeNode* root) {
      int ans = f(root).maxSum;
      return ans>=0?ans:0;
    }
};
