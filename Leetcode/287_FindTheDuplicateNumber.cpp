#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int found = INT_MIN;
        for (int i = 0; i < nums.size(); ++i)
        {   
            int index = abs(nums[i]) - 1;
            
            if (nums[index]<0)
            {
                found =abs(nums[i]);
                
            }
            else{
                nums[index] = -1*nums[index];
            }
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        return found;
    }
    
};

/*TORTOISE-HAIR ALGO
To use the slow fast pointer approach to find cycle in a sequence
Also called Floyd's cycle detection algorithm
AS:O(1) , TC: O(n)
*/
class Soln{
public:
    int findDuplicate(vector<int>& nums){
        if (nums.size()==2)
        {
            return nums[0];
        }
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (fast!=slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

//Binary Search Type Solution; O(1) space O(nlogn) solution
class Sol {

public:

int findDuplicate(vector<int>& nums) {
    int n=nums.size()-1;
    int low=1;
    int high=n;
    int mid;
    while(low<high){
        mid=(low+high)/2;
        int count=0;
        for(int num:nums){
            if(num<=mid) count++;
        }
        if(count>mid) high=mid;
        else low=mid+1; 
    }
    return low;
}
};