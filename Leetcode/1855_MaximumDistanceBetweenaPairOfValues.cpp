class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxx = 0;
        for(int i=0;i<nums1.size();i++){
            int target = nums1[i];
            vector<int>::iterator up;
            up = upper_bound(nums2.begin(),nums2.end(),target, greater<int>());
            int idx = up - nums2.begin();
            maxx = max(maxx,idx-1-i);
        }
        return maxx;
    }
};