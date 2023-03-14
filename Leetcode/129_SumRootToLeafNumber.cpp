#include <bits/stdc++.h>
using namespace std;
int main(){
    
    return 0;
}
//Definition for a binary tree node.
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

    void dfs(int sum, TreeNode* root, int& totalSum){
        if (!root) return;
        if (!root->left && !root->right){
        sum=(10*sum + root->val);
            totalSum+=sum;
            return;
        }
        sum=(10*sum + root->val);
        dfs(sum, root->left,totalSum);
        dfs(sum, root->right,totalSum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int totalSum = 0;
        dfs(sum,root, totalSum);
        return totalSum;
    }
};