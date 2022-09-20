#include <bits/stdc++.h>
using namespace std;

void reverse(int start, int end, vector<int>& v){
    for(int i = 0; i<(end-start)/2;i++){
        int temp = v[end-i-1];
        v[end-i-1] = v[i];
        v[i] = temp;
    }
}

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    
    int x = permutation[n-1];
 	int i,j ;
    for (i = n-2; i >= 0; i--)
    {
    	if(permutation[i]<permutation[i+1]) break;
    }
    if (i==-1) {
    	reverse(permutation.begin(), permutation.end());
    	return permutation;
    }
    for (j = n-1; j >= 0; j--)
    {
    	if(permutation[j]>permutation[i]){
    		break;
    	}
    }
    swap(permutation[i],permutation[j]);
    reverse(permutation.begin() + i +1, permutation.end());
    return permutation;

}