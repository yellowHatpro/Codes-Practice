class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        vector<vector<int>> a(n, vector<int> (n, 0));
        vector<vector<int>> b(n, vector<int> (n, 0));
        vector<vector<int>> c(n, vector<int> (n, 0));
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                a[j][n-1-i] = mat[i][j];
                b[n-1-i][n-1-j] = mat[i][j];
                c[n-1-j][i] = mat[i][j];
            }
        }
        if (target==mat || target==a || target==b || target==c){
            return true;
        }
        return false;
    }
};