#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    std::map<int, int> m;
    for (int i = 1; i <= n; ++i)
    {   int p;cin>>p;
        m[p] = i;  
    }
    for (int i = 1; i <= n; ++i)
    {
        cout<<m[i]<<" ";
    }
cout<<endl;
    return 0;
}