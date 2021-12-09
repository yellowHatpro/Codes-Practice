#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for (int i=0;i<nums.size();i++){
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};

/*O(1) space
The idea is to store two numbers (nums[i] and nums[nums[i]]) at the same location.

The important point to be noted is that all numbers in the array are less than size of the array.

Example - Lets say we have two numbers in the array a = 3 , b = 2 and the size of the array is n = 5

We can store both 3 and 2 in a as follows:-

a = a + b * n

To get initial value of a we do a%n
To get the value of b we do a/n

a = a + b * n = 3 + 2*5 = 13
 
a % n = 13 % 5 = 3 mod gives me remainder

a / n = 13 / 5 = 2 divide gives quotient

So we will use this technique to store two numbers in one location.

Why is it important that all numbers must be less than size of the array ?

Its because when we do

    for(int i=0;i<n;i++)
    {
        nums[i] = nums[i] + n*(nums[nums[i]]);
    }
There may be cases when we have lost the value of nums[i] as it has already been replaced by nums[nums[i]].
So in such cases we need to get the previous values of nums[i] or a
This is done by finding nums[nums[i]] % n

    for(int i=0;i<n;i++)
    {
        nums[i] = nums[i] + n*(nums[nums[i]]%n);
    }

    */

//Optimised Solution
class Solution{
    public:
    vector<int> buildArray(vector<int>& nums ){
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            nums[i] = nums[i] + n*nums[nums[i]];
        }
        for(int i =0 ; i< n ; i++){
            nums[i] = nums[i]/n;
        }
return nums;
    }
    
};