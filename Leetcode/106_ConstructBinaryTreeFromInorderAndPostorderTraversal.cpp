#include <bits/stdc++.h>
using namespace std;
//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *Tree(vector<int>& in, int x, int y,vector<int>& po,int a,int b, map<int, int> &inMap){
        if(x > y || a > b)return nullptr;
        TreeNode *node = new TreeNode(po[b]);
        int inRoot = inMap[node->val];
        int numsLeft =inRoot-x;
        node->left  = Tree(in,x,inRoot-1,po,a,a+numsLeft-1, inMap);
        node->right = Tree(in,inRoot+1,y,po,a+numsLeft,b-1, inMap);
        return node;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& po){
        map<int,int> inMap;
        for (int i = 0; i < in.size(); ++i)
        {
            inMap[in[i]] = i;
        }
        return Tree(in,0,in.size()-1,po,0,po.size()-1, inMap);
    }
};