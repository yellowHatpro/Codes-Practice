#include <bits/stdc++.h>
using namespace std;
string uniqueChar(string str) {
	int len = str.size();
	   char * ret = new char[len]; // max size possible
    int j = -1;
    unordered_set<char> mp;
    for(int i=0; i<len; i++)
    {
        if(mp.count(str[i])==0) // not present
            ret[++j] = str[i], mp.insert(str[i]);
    }
    ret[++j] = 0;
    return ret;

    
}


