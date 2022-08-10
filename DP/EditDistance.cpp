#include <bits/stdc++.h>
using namespace std;

//Simple Recursive Solution
int editDistance(string s1, string s2) {
	
    if(s1.size()==0 || s2.size()==0){
        return max(s1.size(),s2.size());
    }
    
    //Recursive step
    if(s1[0]==s2[0]){
        return editDistance(s1.substr(1), s2.substr(1));
    }
    else{
        int x = editDistance(s1.substr(1),s2.substr(1));//Replace
        int y =  editDistance(s1.substr(1),s2); // Insert
        int z =  editDistance(s1,s2.substr(1)); // Delete
 		return min({x,y,z})+1;
    }
}

//Memoization Solution

int editDistance_mem(string s1, string s2, int **output){
    //helper function that uses same logic as that of the recursive solution, with a bit of modification
    //copy and paste the recursive solution
    int m = s1.size();
    int n = s2.size();
     if(s1.size()==0 || s2.size()==0){
        return max(s1.size(),s2.size());
    }
    
    //If answer is there in output matrix , return it from output
    if(output[m][n]!=-1){
        return output[m][n];
    }
   
        //else make a answer variable that stores the answer
         int ans;
    //Recursive step
    if(s1[0]==s2[0]){
         ans = editDistance_mem(s1.substr(1), s2.substr(1),output);
    }
    else{
        
        int x = editDistance_mem(s1.substr(1),s2.substr(1),output);
        int y =  editDistance_mem(s1.substr(1),s2,output);
        int z =  editDistance_mem(s1,s2.substr(1),output);
        ans = min(min(x,y),z)+1;
    } //output[m][n] coz recursively the length of both strings is reducing ..
    output[m][n] = ans;
    return ans;
}
int editDistance_mem(string s1, string s2){
    int m = s1.size();
    int n = s2.size();
    //create a matrix of size m+1 x n+1
    int** output = new int*[m+1];
    for(int i=0;i<=m;i++){
        output[i] = new int[n+1];
        for (int j = 0; j <=n; j++)
        {// Initialize matrix with -1
            output[i][j] = -1;
        }
    } // return a helper function 
    return editDistance_mem(s1,s2,output);
}

//DP Solution
int editDistance_DP(string s1 , string s2){
    //create the matrix of size m+1 x n+1
    int m = s1.size();
    int n = s2.size();
    int** dp = new int*[m+1];
    for (int i = 0; i <=m; i++)
    {
        dp[i]= new int[n+1];
    }
    //Fill 1st row
    for(int i= 0;i<=m;i++){
        dp[0][i] = i;
    }
    //Fill 2nd row
    for (int i = 0; i <=n; i++)
    {
        dp[i][0] = i;
    }
    for (int  i = 1; i <=m; i++)
    {
        for (int j = 0; j <=n; j++)
        {
            //first letter check
            if(s1[m-i]==s2[n-j]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                //check the 3 operations
                int a =dp[i-1][j];
                int b =dp[i][j-1];
                int c =dp[i-1][j-1];
                dp[i][j] = min(min(a,b),c)+1;
            }
        }
        
    }
    
    return dp[m][n];
    
}