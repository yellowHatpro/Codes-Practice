#include <array>
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    if (s==t) {
    cout<<"Yes"<<endl;
    return 0;
  }
    for (int i = 0; i < s.size()-1; i++) {
      if (s[i]==t[i+1] && s[i+1]==t[i]){
      swap(s[i],s[i+1]);
      if (s==t){
        cout<<"Yes"<<endl; 
        return 0;
      }
      swap(s[i],s[i+1]);
    }
    }
    cout<<"No"<<endl;
    return 0;
  }
