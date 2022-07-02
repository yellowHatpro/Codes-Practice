#include <bits/stdc++.h>
using namespace std;
int findFrequency(vector<int> v, int x){
    // Your code here
    map<int,int> m;
    for (int i = 0; i < v.size(); ++i)
    {
    	if (v[i]==x)
    	{
    		m[x]++;
    	}
    }
    return m[x];
}
int main(){
	
	return 0;
}