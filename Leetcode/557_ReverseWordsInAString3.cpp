#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	void reverse(string &s){
		int start = 0;
		int end = s.size();
		for (int i = start; i < end/2; ++i)
		{
			char temp = s[end - i - 1];
			s[end-i-1] = s[i];
			s[i] = temp;
		}
	}

    string reverseWords(string s) {
     vector<string> v;
     int i = 0;
     int j = 0;
     while(j!=s.length()-1){
     	if (s[j]==' ')
     	{	
     		v.push_back(s.substr(i,j-i));
     		i = j+1;
     	}
     	j++;
     	if (j==s.length()-1)
     	{
     		     v.push_back(s.substr(i,j-i+1));

     	}
     }
     for (int i = 0; i < v.size(); ++i)
     {
     	reverse(v[i]);
 
     }
     string ssss = "";
     for (int i = 0; i < v.size(); ++i)
     { 
     ssss+=v[i];	
     ssss+=" ";
     }
     ssss = ssss.substr(0,ssss.size()-1);
    return ssss;
    }
};

int main(){
	string s = "Let's take LeetCode contest";
	Solution ss = Solution();
	cout<<ss.reverseWords(s);
	return 0;
}