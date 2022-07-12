#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//Break the cycle
	// rotate cyclic array such that max element is at the end, coz only distinguished feature of ques is that we know maxElement's next greatest is none.
	void reverseArray(vector<int>& v, int start, int end) {
    while (start < end) {
        swap(v[start], v[end]);
        start++;
        end--;
    }
}
	void rightClockWiseRotate( vector<int>& v, int d, int n) {
    if (d == 0) return;
    d = d % n;  // In case d>=n
    reverseArray(v, 0, n - 1);
    reverseArray(v, 0, d - 1);
    reverseArray(v, d, n - 1);
}
//Reversal program done
//------------------------------------------------------------------------------

    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> res;
        int maxE=INT_MIN;
        int maxI;
        //find greatest element and index 
        for (int i = 0; i < nums.size(); ++i)
        {
        	if (nums[i]>=maxE)
        		{
        			maxI = i;	
        			maxE = nums[i];
        		}	

        }
        //rotate array st largest element is at last 
        int d = nums.size()-1-(maxI);
        rightClockWiseRotate(nums,d,nums.size());
        for (int i = nums.size()-1; i >= 0; i--)
        {
        	if (s.empty())
        	{
        		res.push_back(-1);
        		s.push(nums[i]);
        	}
        	else{
        		while(s.size()>=1 && s.top()<=nums[i] ){
                    s.pop();
        		}
                if (s.empty()){
                    res.push_back(-1);
                        s.push(nums[i]);
                }
                else {
                    res.push_back(s.top());
        		s.push(nums[i]);
                }
        		
        	}
        }
        //reverse arr
        reverse(res.begin(),res.end());
        //reverse array acc to the intial nums array
        rightClockWiseRotate(res,maxI+1,res.size());
        cout<<endl;
        return res;
    }

};