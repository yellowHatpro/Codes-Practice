#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long titleToNumber(string columnTitle) {
        long long count=0;
        long long length = columnTitle.length();
        long long i=1;
        while(length!=0){
            count+=(int(columnTitle[length-1])-64)*i;
            i*=26;
            length-=1;
        }
        return count;
    }
};