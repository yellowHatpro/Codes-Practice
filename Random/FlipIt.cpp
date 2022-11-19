#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n,x; // x is replacable As
  cin>>n>>x;
  string s;cin>>s;
  int cnt = 0;
  int maxCnt=0;
  int cntX = x;
  for(int i = 0;i<s.length();i++){
    if (s[i]=='K') cnt++;
    else {
      if (cntX<=0){
        maxCnt = max(cnt,maxCnt);
        cntX = x;
        cnt= 0;
      } else {
        cntX--;
        cnt++;
      }
    }
    maxCnt= max(cnt,maxCnt);
  }
  cout<<maxCnt<<endl;

}

int main(){
  int t;cin>>t;
  while(t--){
    solve();
  }
}