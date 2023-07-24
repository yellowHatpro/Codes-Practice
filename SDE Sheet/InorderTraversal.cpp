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
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> inorder;
    stack<TreeNode*> s;
    while (1) {
      if (root){
      s.push(root);  
      root=root->left;
      } else {
        if (s.empty()) break;
        root = s.top();
        inorder.push_back(root->data);
        s.pop();
        root = root->right;
      }
    }
    return inorder;
}

void inorderHelper(TreeNode* root, vector<int>& inorder){
  if (!root) return;
  inorderHelper(root->left, inorder);
  inorder.push_back(root->data);
  inorderHelper(root->right, inorder);
}

vector<int> getInOrderTraversal_Recursive(TreeNode *root)
{
    vector<int> inorder;
    inorderHelper(root, inorder);
    return inorder;
}
