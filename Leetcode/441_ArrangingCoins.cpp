class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1, ans = 0;
        
        while (n) {
            n -= i++;
            if(n >= 0) ++ans;
            else break;
        }
        
        return ans;
    }
};