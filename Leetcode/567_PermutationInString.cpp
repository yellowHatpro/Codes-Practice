#include <bits/stdc++.h>
using namespace std;



class SolutionTODO2 {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        if (s1.size()>s2.size()) return false;
        vector<int> ori_cnt(26);
        for (int i = 0; i < s1.size(); ++i) {
            ori_cnt[s1[i] - 'a']++;
        }
    

        int good=0;
        std::vector<int> cnt(26,0);
        for (int i = 0; i < 26; ++i)
        {
            good+=(cnt[i]==ori_cnt[i]);
        }
        for (int l=0,r=0;l<n; ) {
            while(l+s1.size()<=r and r<s2.size()){
                if (cnt[s2[r]-'a']==ori_cnt[s2[r]-'a'])
                {
                    good--;
                }
                cnt[s2[r]-'a']++;
                if (cnt[s2[r]-'a']==ori_cnt[s2[r]-'a'])
                {
                    good++;
                }
                r++;
            }
            if (good==26)
            {
                return true;
            }
                if (cnt[s2[l]-'a']==ori_cnt[s2[l]-'a'])
                {
                    good--;
                }
                cnt[s2[l]-'a']++;
                if (cnt[s2[l]-'a']==ori_cnt[s2[l]-'a'])
                {
                    good++;
                }
                l++;
        }
        return false;

    }
};

class SolutionTODO {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        if (s1.size()>s2.size()) return false;
                vector<int> ori_cnt(26);
        for (int i = 0; i < s1.size(); ++i) {
            ori_cnt[s1[i] - 'a']++;
        }
    
        vector<vector<int>> psum(n+1,vector<int>(26,0));
        for (int i = 0; i < s2.size(); ++i)
        {
            psum[i+1]=psum[i];
            psum[i+1][s2[i]-'a']++;
        }
        for (int l=0,r=s1.size();l<n;l++,r++)
        {
            bool all_same=true;
            for (int i = 0; i < 26; ++i) {
            all_same&=(psum[r][i]-psum[l][i]==ori_cnt[i]);
            }
            if (all_same) return all_same;
        }
        return false;
    }
};

int main(){
	Solution s = Solution();
	string s1 = "ab";
	string s2 = "eidbaooo";
	cout<<s.checkInclusion(s1,s2)<<endl;
}