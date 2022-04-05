#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res=-1;
        int manhatten=INT_MAX;
        for (int i = 0; i < points.size(); ++i)
        {
        	if (points[i][0]==x||points[i][1]==y)
        	{if (abs(x-points[i][0])+abs(y-points[i][1])<manhatten)
        	{	manhatten=abs(x-points[i][0])+abs(y-points[i][1]);
        		
        		res=i;
        	}        		
        	}
        }
        return res;
    }
};