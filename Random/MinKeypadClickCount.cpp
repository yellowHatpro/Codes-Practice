#include <bits/stdc++.h>
using namespace std;

int minimumKeypadClickCount(string text){
    unordered_set<char> s;
    vector<int> temp(26, 0);
    int ans=0;
    for(int i=0; i<text.size(); i++){
        if(s.find(text[i])!=s.end()){
            ans += temp[text[i]-'a'];
        }
        else{
            int count = 1;
            s.insert(text[i]);
            if(s.size()%9!=0&&s.size()>=9)
                count++;
            temp[text[i]-'a'] = count;
            ans += count;
        }
    }
	return ans;
	}

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	cout<<minimumKeypadClickCount(s);
	return 0;
}