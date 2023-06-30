#include <algorithm>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
  string N;cin>>N;
  sort(N.begin(), N.end());
  int ans = 0;
  if (N[1]!='0'){
          for(int i=1; i<N.size(); i++){
            int l = 0, r = 0;
            for(int j=0; j<i; j++) l = l*10+N[j]-'0';
            for(int j=i; j<N.size(); j++) r = r*10+N[j]-'0';
            ans = max(ans,l*r);
        }
  }
  while(next_permutation(N.begin(),N.end())){
  if (N[1]!='0'){
        for(int i=1; i<N.size(); i++){
            int l = 0, r = 0;
            for(int j=0; j<i; j++) l = l*10+N[j]-'0';
            for(int j=i; j<N.size(); j++) r = r*10+N[j]-'0';
            ans = max(ans,l*r);
        }
    }
  }
  cout<<ans<<endl;
}
