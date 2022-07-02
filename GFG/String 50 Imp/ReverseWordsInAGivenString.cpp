#include <bits/stdc++.h>
using namespace std;
 string reverseWords(string S) 
    { 
        // code here 
       vector<string> v;
       int start=0;
       int len = 0;
       for (int i = 0; i < S.length(); ++i)
       {
       	if (S[i]!='.')
       	{
       		len++;
       	}
       	else{
       		v.push_back(S.substr(start,len));
       		start = i+1;
       		len = 0;
       	}
       }
       v.push_back(S.substr(start,len));
      
       for (int i = 0; i < v.size()/2; ++i)
       {
       	swap(v[i],v[v.size()-1-i]);
       }
       string res = "";
       for (int i = 0; i < v.size(); ++i)
       {
       	res+=v[i];
       	res+='.';
       }
       res.erase(res.length()-1);
       return res;
    } 
int main(){
	
	return 0;
}