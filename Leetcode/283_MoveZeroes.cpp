class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curr = 0;
        int prev = 0;
        while(curr!=nums.size()){
            if (nums[curr]==0){
                curr++;
            } else{
                nums[prev++] = nums[curr++];
            }
        }
        while(prev<=curr){
            nums[prev++] = 0;
        }
    }
};

class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        int curr = 0;
        int prev = 0;
        while(curr!=nums.size()){
            if (nums[curr]!=0){
                swap(nums[prev++],nums[curr]);
            }
            curr++;
        }
      
    }
};