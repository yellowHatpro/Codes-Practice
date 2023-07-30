#include <bits/stdc++.h>
using namespace std;

// return the Kth largest element in the given BST rooted at 'root'

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    public:

    void f(Node* root, int &k, int & ans){
        if (!root || k==0) return;
        f(root->right,k,ans);
        k--;
        if (k==0){
          ans = root->data;
          return;
          }
        f(root->left,k,ans);
    }

    int kthLargest(Node *root, int K)
    {
       int ans=-1;
       f(root,K, ans);
       return ans;
    }
};
