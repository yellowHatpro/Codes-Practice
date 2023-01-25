#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	vector<int> NSL(vector<int> heights){
		vector<int> res;
		stack<pair<int,int>> s;
		for (int i = 0; i < heights.size(); ++i)
		{
			if(s.empty()){
				res.push_back(-1);
			} else if (s.size()>0 && s.top().first<heights[i]){
				res.push_back(s.top().second);
			} else {
				while(s.size()>0 && s.top().first>=heights[i]){
					s.pop();
				}
				if (s.empty()){
					res.push_back(-1);
				} else {
					res.push_back(s.top().second);
				}
			}
			s.push({heights[i],i});
		}
		return res;
	}

	vector<int> NSR(vector<int> heights){
		vector<int> res;
		stack<pair<int,int>> s;
		for (int i = heights.size()-1;i>=0;i--){
			if (s.empty()){
				res.push_back(heights.size());
			} else if (s.size()>0 && s.top().first<heights[i]){
				res.push_back(s.top().second);
			} else if (s.size()>0) {
				while(s.size()>0 && s.top().first>=heights[i]){
					s.pop();
				}
				if (s.empty()){
					res.push_back(heights.size());
				} else {
					res.push_back(s.top().second);
				}
			}
			s.push({heights[i],i});
		}
		reverse(res.begin(), res.end());
		return res;
	}

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsl = NSL(heights);
        vector<int> nsr = NSR(heights);
        int maxi = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
        	maxi = max(maxi,(nsr[i]-nsl[i]-1)*heights[i]);
        }
        return maxi;
    }
};