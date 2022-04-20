#include <bits/stdc++.h>
using namespace std;
void print(int x){
    vector<int> v;
   int count=0;
    int i=0;
    while(x!=0){
        if(x%10!=0){
        v.push_back((x%10)*pow(10,i));
        count++;
        }
        x/=10;
        i++;
    }
    cout<<count<<endl;
    for(int i=0;i<count;i++){
        cout<<v[i]<<" ";
    }
}
int main(){
    int n;cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;cin>>x;
        print(x);
    }
    return 0;
}