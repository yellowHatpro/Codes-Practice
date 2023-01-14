//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int *arr, int n, int m) {
        // code here
        int wL = 0;
        int wR = 0;
        int bestWindow = 0;
        int zeroCount = 0;
        while(wR<n){
            if (zeroCount<=m){
                if (arr[wR]==0)
                    zeroCount++;
                wR++;
            }
            else {
                if (arr[wL]==0){
                    zeroCount--;
                }
                wL++;
            }
            if (wR-wL>bestWindow && zeroCount<=m){
                bestWindow = wR-wL;
            }
        }
        return bestWindow;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends