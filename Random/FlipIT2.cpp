#include <bits/stdc++.h>
using namespace std;

int main(){
  int tt = 1;
  cin>>tt;
  while(tt--){
    int n,x;
    cin>>n>>x;
    string s;
    cin>>s;
    vector<int> pre(s.size(),0);
    int cnt = 0;
    int i =0, j= 0;
    int ans = -1;
while(j<s.size()){
  if (s[j]=='A'){
    cnt++;
  }
  if (cnt <=x){
    ans = max(ans, (j-i)+1);

  }else {
    while(cnt> x && i<j){
      if (s[i]=='A'){
        cnt--;
      }
      i++;
    }
   
      }
       j++;
    }
    cout<<ans<<endl;
  }
  return 0;
}