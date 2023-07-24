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

vector<int> getPostOrderTraversal(TreeNode *root)
{
  if (!root) return {};
  vector<int> postorder;
  stack<TreeNode*> s;
  while(true){
    if (root){
      s.push(root);
      root=root->left;
    } else {
      if (s.empty()) break;
      TreeNode* curr = s      .top();
      s.pop();
      if (curr->right){
        postorder.push_back(curr->right->data);
        s.push(curr->right);
      }
      postorder.push_back(curr->data);
    }
  }
  return postorder;

}
