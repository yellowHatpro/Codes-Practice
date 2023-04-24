#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    string reverseWords(string s) {
    	string res="";
    	stringstream ss(s);
    	string token;
    	while(getline(ss,token,' ')){
    		reverse(token.begin(), token.end());
				res+=token;
				res+=" ";
    	}
			res = res.substr(0,res.size()-1);
    	return res;
    }
};

int main(){
	string s = "Let's take LeetCode contest";
	Solution ss = Solution();
	cout<<ss.reverseWords(s);
	return 0;
}