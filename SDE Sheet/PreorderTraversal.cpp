#include <bits/stdc++.h>
using namespace std;

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

vector<int> getPreOrderTraversal(TreeNode *root)
{
  if (!root) return {};
  vector<int> preorder;
  stack<TreeNode*> s;
  s.push(root);
  while(true){
    if (s.empty()) break;
    TreeNode* curr = s.top();
    preorder.push_back(curr->data);
    s.pop();
    if (curr->right) s.push(curr->right);
    if (curr->left) s.push(curr->left);
  }
  return preorder;
}
