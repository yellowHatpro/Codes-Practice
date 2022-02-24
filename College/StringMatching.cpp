//String Matching
//Brute Force Approach
//Input : "ashutosh aswal"
//Pattern: "ashu"
//Output: Pattern found at index 0
//Time Complexity : Theta(n-m+1)m

#include <bits/stdc++.h>
using namespace std;

int main(){
string s1= "ashutosh aswal";
string s2 = "aswal";
int s1_size = s1.length();
int s2_size = s2.length();
int slide = s1_size-s2_size;
for (int  i = 0; i <=slide; i++)
{
    for (int j = 0; j < s2_size; j++)
    {
        if (s1[i+j] != s2[j])
            break;
        if (j == s2_size-1)
            cout << "Pattern found at index " << i << endl;
    }
}

}