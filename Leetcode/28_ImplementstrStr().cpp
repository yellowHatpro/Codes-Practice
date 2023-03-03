#include <iostream>
using namespace std;
  
 class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()>haystack.length()) return -1;
        auto itr = haystack.find(needle);
        if (itr == string::npos){
            return -1;
        } else {
            return itr;
        }
    }
};