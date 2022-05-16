#include <bits/stdc++.h>
using namespace std;
bool isSubstring(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();
 
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;
 
        /* For current index i, check for
 pattern match */
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
 
        if (j == M)
            return true;
    }
 
    return false;
}
int main(){
    string s1;cin>>s1;
    string one = "1111111";
    string zero="0000000";
    if(isSubstring(one,s1)||isSubstring(zero,s1)){
        cout<<"YES"<<endl;
    }   
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}