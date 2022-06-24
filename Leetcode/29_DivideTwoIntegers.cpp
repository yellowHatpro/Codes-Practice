#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int divide(int dividend, int divisor) {
if(dividend==(1<<31) && divisor==-1) return INT_MAX;
if(dividend==(1<<31) && divisor==1){
return INT_MIN;
}
bool sign=true;
if((dividend<=0&& divisor>=0) || (dividend >=0 && divisor<=0)){
sign = false;
}
int result =0;
long long undividend=abs(dividend);
long long undivisor=abs(divisor);
while(undividend>=undivisor){
int count=0;
while(undividend>=(undivisor<<(count+1))){
count++;
}
result+=(1<<count);
undividend-=(undivisor<<count);
}
return (sign)? result:-result;
}
};