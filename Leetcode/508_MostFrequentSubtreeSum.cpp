#include <bits/stdc++.h>
#include <unordered_map>
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
  unordered_map<int, int> m;
  int maxFreq = 0;
  int f(TreeNode *root) {
    if (!root)
      return 0;
    int lSum = f(root->left);
    int rSum = f(root->right);
    int res = lSum + rSum + root->val;
    m[res]++;
    maxFreq = max(maxFreq, m[res]);
    return res;
  }

  vector<int> findFrequentTreeSum(TreeNode *root) {
    int finalSum = f(root);
    vector<int> res;
    for (auto itr : m) {
      if (itr.second == maxFreq) {
        res.push_back(itr.first);
      }
    }
    return res;
  }
};
