#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> getMinMax(long long a[], int n) {
  	int min = INT_MAX;
  	int max = INT_MIN;
   for (int i = 0; i < n; ++i)
    {
    	if (a[i]<min)
    	{
    		min=a[i];
    	}
    	if (a[i]>max)
    	{
    		max=a[i];
    	}
    }
    pair<long long,long long> p(min,max);
    return p; 
}

