#include <bits/stdc++.h>
using namespace std;

void printSubsetsHelper(int n, string str, int k){
	if (k>n)
	{
		cout<<str<<endl;
		return;
	}
	else{
	printSubsetsHelper(n,str+to_string(k),k+1);
	printSubsetsHelper(n,str,k+1);
}
}

void printSubsets(int n){
	printSubsetsHelper(n,"",1);
}

int main(){
	 printSubsets(5);
}