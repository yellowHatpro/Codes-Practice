#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	bool bfs(int curr, int x,int y, int z, int target, vector<int>&vis){

		vector<int> water{x,-x,y,-y};

		queue<int> q;
		q.push(curr);
		vis[curr] = 1;
		while(!q.empty()){
			int waterSupp = q.front();
			q.pop();

			if (target==waterSupp) return true;

			for (int i = 0; i < 4; ++i)
			{
				int waterSuppNew = waterSupp + water[i];
				if (waterSuppNew>=0 && waterSuppNew<=z && !vis[waterSuppNew]){
					q.push(waterSuppNew);
					vis[waterSuppNew] = 1;
				}
			}
		}
		return false;
	}

    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
    	int x = jug1Capacity;
    	int y = jug2Capacity;
    	int z = x+y;
        vector<int> vis(z+1);
        return bfs(0,x,y,z,targetCapacity,vis);
    }
};