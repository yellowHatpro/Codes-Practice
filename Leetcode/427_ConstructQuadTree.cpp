#include <bits/stdc++.h>
using namespace std;
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
	bool isNodeLeaf(int i1, int j1, int length, vector<vector<int>>& grid){
		int checker = grid[i1][j1];
		for (int i = i1; i < i1 + length; ++i)
		{	
			for (int j = j1; j < j1 + length; ++j)
			{
				if (grid[i][j]!=checker){
					return false;
				}
			}
		}
		return true;
	}

	Node* f(int i, int j, vector<vector<int>>& grid, int length){
		if (isNodeLeaf(i,j, length, grid)){
			return new Node(grid[i][j], true);
		} else {
			Node* root = new Node(false,false);
			root->topLeft = f(i,j,grid, length/2);
			root->topRight = f(i,j+length/2, grid, length/2);
			root->bottomLeft = f(i+length/2, j, grid, length/2);
			root->bottomRight = f(i+length/2, j+length/2, grid, length/2);
			return root;
		}
	}

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return f(0,0,grid, n);
    }
};