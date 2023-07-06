#include <bits/stdc++.h>
using namespace std;
// This question permits duplicate values, so instead of using map, we try to find the node in inorder array, and once found, we replace the value there with -1, and get the index .
struct Node
{
  int data;
  Node* left;
  Node* right;
};


class Solution{
    public:
    
    Node* f(int n, int*&in, int inS, int inE, int*&pre, int preS, int preE ){
      if (inS > inE || preS > preE) return nullptr;
      Node* root = new Node(pre[preS]);
      int inRootIndex = 0;
      for (int i = 0; i < n ; i++) {
        if (in[i]==pre[preS]) {
          inRootIndex = i;
          in[i] = -1;
          break;
        } 
      }
      int leftRangeIn = inRootIndex - inS;
      root->left = f(n,in, inS, inRootIndex-1, pre, preS+1, preS+leftRangeIn);
      root->right = f(n, in, inRootIndex+1, inE,pre, preS+leftRangeIn+1, preE);
      return root;
  }

    Node* buildTree(int in[],int pre[], int n) {
      return f(n,in,0,n-1, pre,0,n-1);
    }
};
