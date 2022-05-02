#include <iostream>
using namespace std;
  
 class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()>haystack.length()) return -1;
        for (int i = 0; i <= haystack.length()-needle.length(); i++)
        {
            for (int j = 0; j < needle.length();  j++)
            {
                if (haystack[i+j] != needle[j])
                    break;
                if (j == needle.length()-1)
                    return i;
            }
            
        }
        return -1;
        
    }
};