#include <bits/stdc++.h>
#include <numeric>
using namespace std;
 template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

vector<int> getTopView(TreeNode<int> *root) {
  vector<int> ans;
  if (!root) return ans;
  queue<pair<TreeNode<int>*,int>> q;
  map<int,int> m;
  q.push({root,0});
  while(!q.empty()){
    auto itr = q.front();
    q.pop();
    TreeNode<int>* curr = itr.first;
    int idx = itr.second;
    if (m.find(idx) == m.end()){
      m[idx] = curr->val;
    }
    if (curr->left) q.push({curr->left,idx-1});
    if (curr->right) q.push({curr->right,idx+1});
  }
  for (auto itr : m) {
    ans.push_back(itr.second);
  }
  return ans;
}


