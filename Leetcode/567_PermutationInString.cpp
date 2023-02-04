#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        map<char, int> mp;
        for (int i = 0; i < n; ++i)
        {
        	mp[s1[i]]++;
        }
        if (n>m) return false;
        int en = 0;
        int st = 0;
        int cnt = 0;
       	while(en<m){
       		if (cnt==n) return true;
       		if (mp[s2[en]]>0){
       			cnt++;
       			mp[s2[en]]--;
                   en++;
       		} else{
       			if (st==en){
       				st++;
       				en++;
       			}
       			 else {
       			 	cnt--;
       			 	mp[s2[st++]]++;
       			 }

       		}

         
    }
    return cnt==n;
}
};

int main(){
	Solution s = Solution();
	string s1 = "ab";
	string s2 = "eidbaooo";
	cout<<s.checkInclusion(s1,s2)<<endl;
}