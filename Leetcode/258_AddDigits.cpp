#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	// One Liner soln : return (num-1)%9 +1;  
	//Concept of digital root 
    int addDigits(int num) {
		if (num==0) return 0;
		if (num%9==0) return 9;
		return num%9;
    }
};