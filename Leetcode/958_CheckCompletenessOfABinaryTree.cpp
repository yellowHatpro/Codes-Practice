#include <bits/stdc++.h>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//TODO : DFS Solution
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool isNull = false;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if (curr == nullptr){
                isNull = true;
            } else {
                if (isNull){
                    return false;
                }
            }
            q.push(curr->left);
            q.push(curr->right);
        }
        return true;
    }
};