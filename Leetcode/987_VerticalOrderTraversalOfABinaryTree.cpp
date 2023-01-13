#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//Multiset is used to store values is sorted order, and can include duplicate values as well

class Solution {

private:
	void verticalTraversalHelper(TreeNode* root, int col,int row, map<int, map<int, multiset<int>>> & hashmap){
		if (!root) return;
		hashmap[col][row].insert(root->val);
		verticalTraversalHelper(root->left, col-1,row+1, hashmap);
		verticalTraversalHelper(root->right, col+1,row+1, hashmap);
	}

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       vector<vector<int>> res;
       map<int, map<int, multiset<int>>> hashmap;
       map<int, map<int, multiset<int>>> ::iterator it;
       int row = 0;
       int col = 0;
       verticalTraversalHelper(root,col,row,hashmap);

       for(auto column: hashmap ){
       	vector<int> col;
       	for (auto rows : column.second){
       		for (auto rowElement : rows.second){
       			col.push_back(rowElement);
       		}

       	}
       	res.push_back(col);
       }

       return res;
    }
};