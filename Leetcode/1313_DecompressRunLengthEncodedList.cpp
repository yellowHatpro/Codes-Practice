class Solution {
public:
vector<int> decompressRLElist(vector<int>& nums) {
int n = nums.size();
vector<int> ans;
for(int i=1;i<n;i+=2)
{
for(int j=nums[i-1];j>0;j--)
{
ans.push_back(nums[i]);
}
}
return ans;
}
};