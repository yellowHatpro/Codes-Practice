class Solution {
public:

    int concatenatedBinary(int n) {
         int M = 1e9+7;
        int len = 0;
        long ans = 0;
        for(int i = 1; i<=n;i++){
            if((i&(i-1))==0) len++; //i is some 2^x number
            ans = ((ans<<len)| i)%M;
        }
        return ans;
    }
};