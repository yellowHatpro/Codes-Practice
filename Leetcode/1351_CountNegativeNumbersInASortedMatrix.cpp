#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int countNegatives(vector<vector<int>> &grid) {
	// brute force
		int i = grid.size(), j = grid[0].size(), x = 0;
		for (int a = 0; a < i; ++a) {
			for (int b = 0; b < j; ++b) {
				if (grid[a][b] < 0) {
					x++;
				}
			}
		}
		return x;
	}
};