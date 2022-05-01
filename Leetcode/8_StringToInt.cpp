class Solution {
public:
    int myAtoi(string s) {
        stringstream res(s);
        int x = 0;
        res>>x;
        return x;
    }
};