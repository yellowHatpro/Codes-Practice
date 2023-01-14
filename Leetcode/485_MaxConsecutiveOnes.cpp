#include <bits/stdc++.h>
using namespace std;

//Sliding Window basics
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int wL = 0;
        int wR = 0;
        int bestWindow = 0;
        while(wR<nums.size()){
            if (nums[wR]==0){
                wR++; 
                wL = wR;
            } else {
                wR++;
            }
            if (wR-wL>bestWindow ){
                bestWindow = wR-wL;
            }
        }
        return bestWindow;
    }
};