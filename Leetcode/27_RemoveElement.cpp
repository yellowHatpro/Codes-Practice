class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
         int count=0;
    int j=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==val)
        {
            count++;
        }
        else
        {
            nums[j]=nums[i];
            j++;
            }           
    }
    return nums.size()-count;
    
}
        
    
};