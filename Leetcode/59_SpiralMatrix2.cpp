#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int left=0,right=n-1,top=0,bottom=n-1;
        int curr = 1;
        while(curr<=n*n){
        	for(int i = left; i<=right; i++){
        		res[top][i] = curr++;
        	}
        	top++;
        	if (left>right || top>bottom) break;
        	for (int i = top; i<=bottom; i++){
        		res[i][right] = curr++;
        	}
        	right--;
        	if (left>right || top>bottom) break;
        	for (int i = right; i>=left; i--) {
        		res[bottom][i] = curr++;
        	}
        	bottom--;
        	if (left>right || top>bottom) break;
        	for (int i = bottom; i>=top; i--) {
        		res[i][left] = curr++;
        	}
        	left++;
        	if (left>right || top>bottom) break;
        }
        return res;
    }
};