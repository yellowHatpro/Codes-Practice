#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	int size = digits.size();
    	vector<int> res;
    	bool isZerothDanger = false;
    	digits[size-1] +=1;
        for (int i = digits.size()-1; i >=0; i--)
        {
        	if (digits[i]>=10)
        		{if(i>0)
        	{	digits[i-1]+=1;
        		digits[i] = digits[i]%10;
        	}
        	else{
        		isZerothDanger = true;
        	}
        	}
        	else{
        		break;
        	}
        }
        if (isZerothDanger)
        {
        	res.push_back(1);
        	res.push_back(digits[0]%10);
        	for (int i = 2; i < size; ++i)
        		{
        			res.push_back(digits[i]);
        		}
        		return res;	
        }
        return digits;
    }
};