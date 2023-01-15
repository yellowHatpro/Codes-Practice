#include <bits/stdc++.h>
using namespace std;


//TODO

struct petrolPump
{
    int petrol;
    int distance;
};

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int arr[n];
       int sum=0;
       for (int i = 0; i < n; ++i)
       {
       		arr[i] = p[i].petrol - p[i].distance;
       		sum+=arr[i];
       }
       if (sum<0) return -1;
       int newsum = 0;
       int curr = 0;
       for (int i = 0; i < n; ++i)
       {
       	if (arr[i]<0 || newsum<=0)
       	{
       	    curr=i+1;
       	} else  {
       	    newsum+=arr[i];
       	}
       }
       return curr;
    }
};