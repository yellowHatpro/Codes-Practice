#include <bits/stdc++.h>
using namespace std;

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
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    stack<TreeNode *> s;
    TreeNode *root;
    for (int i = 0; i < nums.size(); i++) {
      TreeNode *temp = new TreeNode(nums[i]);
      if (s.empty()) {
        root = temp;
      } else if (!s.empty() and s.top()->val < nums[i]) {
        while (!s.empty() and s.top()->val < nums[i]) {
          s.pop();
        }
        if (!s.empty()) {
          TreeNode *oldRight = s.top()->right;
          s.top()->right = temp;
          temp->left = oldRight;
        } else {
          TreeNode *oldHead = root;
          root = temp;
          root->left = oldHead;
        }
      } else {
        s.top()->right = temp;
      }
      s.push(temp);
    }
    return root;
  }
};
