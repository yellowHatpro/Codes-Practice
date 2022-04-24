class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n==2||n==1) return true;
        else if (n%2!=0||n==0) return false;
        bool val = isPowerOfTwo(n/2);
        if (val) return true;
        else return false;
    }
};