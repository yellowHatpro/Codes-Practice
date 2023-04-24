#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int cnt = 0;
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size()>1){
            cnt = pq.top();
            pq.pop();
        	int x = pq.top();
        	pq.pop();
        	if (x-cnt!=0) {
        	 	pq.push(abs(x-cnt));
			 	cnt = abs(x-cnt);}
        }
        return pq.size()==0 ? 0 :pq.top();
    }
};