#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
  }
};

class Solution {
  public:

    void mirror(Node* root) {
      if (!root) return;
      Node* lt = root->left;
      Node* rt = root->right;
      root->left = rt;
      root->right = lt;
      mirror(root->left);
      mirror(root->right);
      return ;
    }
};
