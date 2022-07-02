#include <bits/stdc++.h>
using namespace std;
vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        vector<int> res;
        long long sum = 0;
        int i = 0;
        int j = 0;
       	while(i<=j && i<n && j<n){
       		if (sum<s)
       		{	sum += arr[j];
       			j++;
       		}
       		else if (sum==s){
       			res.push_back(i+1);
       			res.push_back(j);
       			return res;
       		}
       		else{
       			sum-=arr[i];
       			i++;
       		}
       	}
       	return {-1};

    }
int main(){
	return 0;
}