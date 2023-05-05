#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> rq, dq;
        for (int i = 0; i < n; ++i)
        {
        	if (senate[i]=='R'){
        		rq.push(i);
        	} else {
        		dq.push(i);
        	}
        }
        while (!dq.empty() && !rq.empty()){
        	int d = dq.front();
        	dq.pop();
        	int r = rq.front();
        	rq.pop();
        	if (d<r){
        		dq.push(d+n);
        	} else {
        		rq.push(r+n);
        	}
        }
        if (dq.empty()){
        	return "Radiant";
        } else return "Dire";
    }
};