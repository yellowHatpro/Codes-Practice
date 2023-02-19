#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(int n) {
        int powa = 1;
        int powb = 1;
        int cnt = 0;
        while(n>0){
        	if (n==1) {
        		cnt++;
        		break;
        	}
        	int x = 1;
        	while(x<n) x*=2;
        	powa = x/2;
        	powb = x;
        	int del = 0;
        	if (n-powa> powb-n){
        		
        	} else {

        	}
        	cnt++;
        }
        return cnt;
    }
};