#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p==q;
        bool a1 = p->val == q->val;
        if (!a1)
        {
            return false;
        }
        bool a = isSameTree(p->left,q->left);
        bool b = isSameTree(p->right, q->right);
        if (!a || !b)
        {
            return false;
        }
        else{
            return true;
        }
        
    }
};
