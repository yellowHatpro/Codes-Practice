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
  vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
    vector<vector<int>> ans;
    TreeNode *temp;
    for (auto itr : queries) {
      temp = root;
      int maxi = -1;
      int mini = -1;
      while (temp) {
        if (!temp) {
          break;
        } else if (temp->val < itr) {
          mini = temp->val;
          temp = temp->right;
        } else if (temp->val > itr) {
          temp = temp->left;
        } else {
          mini = temp->val;
          break;
        }
      }
      temp = root;
      while (temp) {
        if (!temp) {
          break;
        } else if (temp->val < itr) {
          temp = temp->right;
        } else if (temp->val > itr) {
          maxi = temp->val;
          temp = temp->left;
        } else {
          maxi = temp->val;
          break;
        }
      }
      ans.push_back({mini, maxi});
    }
    return ans;
  }
};
