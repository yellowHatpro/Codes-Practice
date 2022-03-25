#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
    	int temp1 = x;
    	long size=0;
       	while(temp1>0){
       		temp1/=10;
       		size++;
       	}
       	long long temp2= x;
       	long long size_b = size;
       	for (int i = 1; i <= size; ++i)
       	{
       		long long q = temp2/(pow(10,size_b-i));
            q%=10;
       		long long m = temp2%(long long)(pow(10,i));
            m/=pow(10,i-1);

       		if (q!=m)
       		{
       			return false;
       		}
       	}
       	return true;
    }
};