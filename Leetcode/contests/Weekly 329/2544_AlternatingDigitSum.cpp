#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int alternateDigitSum(int n) {
        bool pos = 1;
        ostringstream ss;
        ss<<n;
        string number = ss.str();
        int res = 0;
        for (int i = 0; i < number.size(); ++i)
        {
        	if (pos){
        		res += (number[i]  - '0');
        		pos  = 0;
        	}
        	else {
        		res -= (number[i] - '0');
        		pos = 1;
        	}
        }
        return res;
    }
};
