#include <iostream>
#include <string>
using namespace std;

//Recursive Slow Solution
int lcs(string s , string t){
//Base case
if(s.length()==0 || t.length()==0){
return 0;
}
//Recursive calls
if (s[0]==t[0]){
    return 1+lcs(s.substr(1),t.substr(1));
}
else{
int a  = lcs(s.substr(1),t);
int b  = lcs(s,t.substr(1));
//redundant step: int c  = lcs(s.substr(1),t.substr(1));
return max(a,b);
}
}

//Memoization Solution
int lcs_memoization(string s , string t , int** output){
    int  m = s.length();
    int  n = t.length();
   
//Base case
if(s.length()==0 || t.length()==0){
return 0;
}
//Check if answer is already computed
if(output[m][n]!=-1){
return output[m][n];
}

 int ans;
//Recursive calls
if (s[0]==t[0]){
     ans =  1+lcs_memoization(s.substr(1),t.substr(1) , output);
}
else{
int a  = lcs_memoization(s.substr(1),t,output);
int b  = lcs_memoization(s,t.substr(1),output);
//redundant step: int c  = lcs(s.substr(1),t.substr(1));
 ans =  max(a,b);
}
//Store answer in memoization table
 output[m][n] = ans;

//Return answer
return ans;
}
int lcs_memoization(string s , string t){
    int m = s.length();
    int n = t.length();
    int **output = new int*[m+1];
    for(int i=0;i<=m;i++){
        output[i] = new int[n+1];
        for (int j = 0; j <=n; j++)
        {
            output[i][j] =-1;
        }
    }

    return lcs_memoization(s,t , output);
}
//Dynamic Programming
int lcs_DP(string s, string t){
    int m = s.length();
    int n = t.length();
    int **dp = new int*[m+1];
    for(int i=0;i<=m;i++){
        dp[i] = new int[n+1];
    }
    //Filling first column
    for(int i=0;i<=m;i++){
        dp[i][0] = 0;
    }
    //Filling first row
    for(int i=0;i<=n;i++){
        dp[0][i] = 0;
    }
    //Working on the rest of the table
    for(int i=1;i<=m;i++){
        for (int j = 1; j <=n; j++)
        {
            if(s[i-1]==t[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                int a = dp[i-1][j];
                int b = dp[i][j-1];
                dp[i][j] = max(a,b);
            }
            
        }
        
    }
    return dp[m][n];
    
}

int main(){
string s = "AGGTAB";
string t = "GXTXAYB";
cout<<lcs_memoization(s,t)<<endl;
cout<<lcs_DP(s,t)<<endl;
cout<<lcs(s,t);
cout<<endl;
return 0;

}
