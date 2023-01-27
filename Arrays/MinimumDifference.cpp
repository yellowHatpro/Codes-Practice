#include <bits/stdc++.h>
using namespace std;




pair<int,int> minDifference(vector<int> a,vector<int> b){
    //Complete this method
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int n = a.size();
    int m = b.size();
    int i = 0;
    int A = 0;
    int B = 0;
    int mini = 0;
    int curr = 0;
    int x = a[0];
    int y = b[0];
    int minX = x;
    int minY = y;
    while(A<n&&B<m){
		x = a[A];
		y = b[B];
    	if (a[A]<b[B]){
    		curr = abs(a[A++]-b[B]);
    	} else {
    		curr = abs(a[A]-b[B++]);
    	}
    	mini = min(mini,curr);
    	if (mini==curr){
    		minX = x;
    		minY = y;
    	}
    }
    while(A<n){
    	x = a[A];
		y = b[B];
		curr = abs(a[A++]-b[m-1]);
    	mini = min(mini,curr );
    	if (mini==curr){
    		minX = x;
    		minY = y;
    	}
    }
    while(B<m){
    	x = a[A];
		y = b[B];
		curr = abs(a[n-1]-b[B++]);
    	mini = min(mini, curr);
    	if (mini==curr){
    		minX = x;
    		minY = y;
    	}
    }
    return {minX,minY};
}