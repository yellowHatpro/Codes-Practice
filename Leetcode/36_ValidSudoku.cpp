#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		map<int,set<int>> row;
		map<int, set<int>> col;
		map<pair<int,int>, set<int>> sq;
		for (int r = 0; r < 9; ++r)
		   {
		   	for (int c = 0; c < 9; ++c)
		   	{
		   		if (board[r][c]=='.') continue;
		   		if (row[r].count(board[r][c]) ||
		   			col[c].count(board[r][c]) || 
		   			sq[{r/3,c/3}].count(board[r][c])){
		   			return false;
		   		}
		   		row[r].insert(board[r][c]);
		   		col[c].insert(board[r][c]);
		   		sq[{r/3,c/3}].insert(board[r][c]);
		   	}
		   }   
		   return true;
    }
};