#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
  TreeNode *left;
  TreeNode *right;
  int data;
  TreeNode(int data) {
    this->left = NULL;
    this->right = NULL;
    this->data = data;
  }
};

/*After putting root into the stack, put the right first, then left
Because its LIFO so while printing/inserting in resulting vector,
it will first insert left and then right
*/
vector<int> preOrderTraversal(TreeNode *root) {
  vector<int> preOrder;
  if (!root)
    return preOrder;
  stack<TreeNode *> s;
  s.push(root);
  while (!s.empty()) {
    root = s.top();
    s.pop();
    preOrder.push_back(root->data);
    if (root->right != NULL)
      s.push(root->right);
    if (root->left != NULL)
      s.push(root->left);
  }
  return preOrder;
}

// O(n) Time and Space
vector<int> inorderTraversal(TreeNode *root) {
  stack<TreeNode *> s;
  TreeNode *node = root;
  vector<int> inOrder;
  while (true) {
    if (node) {
      s.push(node);
      node = node->left;
    } else {
      if (s.empty())
        break;
      node = s.top();
      s.pop();
      inOrder.push_back(node->data);
      node = node->right;
    }
  }
  return inOrder;
}

// TC -> O(n), SC -> O(2n + n)
vector<int> postOrderTraversal(TreeNode *root) {
  stack<TreeNode *> s1, s2;
  vector<int> postOrder;
  s1.push(root);
  while (!s1.empty()) {
    root = s1.top();
    s1.pop();
    s2.push(root);
    if (root->left)
      s1.push(root->left);
    if (root->right)
      s1.push(root->right);
  }
  while (!s2.empty()) {
    postOrder.push_back(s2.top()->data);
    s2.pop();
  }
  return postOrder;
}
