class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0;
       if (low%2!=0 and high%2!=0){
          ans = 1 + (high-low)/2;
       } 
        else {
             ans =ceil(double(high-low)/2);
        }
        return ans;
    }
};