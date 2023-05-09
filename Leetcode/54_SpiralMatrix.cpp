#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int bottom = matrix.size() -1 ;
        int left = 0;
        int right = matrix[0].size() - 1;
        vector<int> res;
        while(1){
        	for (int i = left; i<=right; i++) res.push_back(matrix[top][i]);
        	top++;
        	if (left>right || top>bottom) break;
        	for (int i = top; i<=bottom; i++) res.push_back(matrix[i][right]);
        	right--;
        	if (left>right || top>bottom) break;
        	for (int i = right; i>=left; i--) res.push_back(matrix[bottom][i]);
        	bottom--;
        	if (left>right || top>bottom) break;
        	for (int i = bottom; i>=top; i--) res.push_back(matrix[i][left]);
        	left++;
        	if (left>right || top>bottom) break;
        }
        return res;
    }
};