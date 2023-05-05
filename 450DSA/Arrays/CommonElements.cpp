#include <bits/stdc++.h>
using namespace std;
//O(n1*log(n2*n3))
class Solution {
    public:    

    	bool bs(int *arr, int n, int x){
    		int l = -1;
    		int r = n;
    		while(r>l+1){
    			int m=(l+r)/2;
    			if (arr[m]<x){
    				l = m;
    			} else r = m;
    		}
    		return arr[r] == x;
    	}
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3) {
           	vector<int> ans;
       		for (int i = 0; i < n1; ++i)
       		{
       			if (i!=0 && A[i]==A[i-1]) continue;
       			if (bs(B,n2,A[i])&&bs(C,n3,A[i])){
       				ans.push_back(A[i]);
       			}
       		}
       		return ans;
        }
};

class SolutionSet {
public:
	vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3) {
		set<int> s1,s2,s3;
		vector<int> ans;
		for (int i = 0; i < n1; ++i)
		{
			s1.insert(A[i]);
		}
		for (int i = 0; i < n2; ++i)
		{
			s2.insert(B[i]);
		}
		for (int i = 0; i < n3; ++i)
		{
			if (s1.find(C[i])!=s1.end() && s2.find(C[i])!=s2.end()){
				//this line checks for duplicates
				if (s3.find(C[i])==s3.end()){
					ans.push_back(C[i]);
				}
				s3.insert(C[i]);
			}
		}
		return ans;

	}

};