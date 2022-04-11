/*Mathematical Definition:
	It is a logical procedure, which is specified by a sub pro

Recursion is defined when a function calls itself by applying some subroutine(other operation) on the parameters by repeating an extra space overhead.

How to approach:
1. BASE CASE
2. RECURSIVE ASSUMPTION
3. SELF WORK

*/
#include <bits/stdc++.h>
using namespace std;



//Q1. Given value n, how many binary strings of length n are there with no consecutive ones.
//n==3: 000 001 010 100 101 .. no consecutive 1s.->5 can be done with fibonnaci function
int fib(int n){
	if (n==0)
	{
		return 0;
	}
	if (n==1)
	{
		return 1;
	}
	return fib(n-1)+fib(n-2);
}

/*Q2. Given: There are n persons, who wants to go to a party.
	There is a constraint that any person can either go alone or can go in a pair.
	Calculate the no. of ways in which n persons will go to party.
*/
int countPartyitems(int n){
	//Base case:
	if (n==1)
	{
		return 1;
	}
	if (n==2)
	{
		return 2;
	}
	//Recursion Assumption
	//2 cases, say a,b,c . Depends on a-> will go alone, or will go in pair.
	//if alone-> it depends on others how they go. That will be n-1 ways.
	//if he goes in pait-> it depends on n-2 people how they go, and with how many people he can pair with..
//self work:
		return countPartyitems(n-1) + (n-1)*countPartyitems(n-2); 
}

//Q3. Given two numbers a and b, calculate a raised to power b recursively.
int powerRecursive(int a, int b){
	if (b==0)
	{
		return 1;
	}
	return a*powerRecursive(a,b-1);
}

int powerOptimisedRecursive(int a,int b){
	//base case
	if (b==0) return 1;
	if (b==1) return a;
	//self work
	int temp = powerOptimisedRecursive(a,b/2);
	//Did you know why we took temp and not returned powerOR*powerOR below?
	//Coz it could have lead to O(b) time complexity due to function calls.
	/*				  f(a,b)
						/\
					   /  \
				f(a,b/2)  f(a,b/2)
					 /		\	
				    /		 \
			f(a,b/4)		f(a,b/4) ..you can calculate the time complexity ig :)	
	*/
	//Saving in temp the result takes only log(b) time for result.
	if (b%2==0)
	{
		return temp*temp; //example a power 6 
	}else{
		return a*temp*temp;//example a power 7 
	}
}


//Basic Patterns using recursion
void pattern1(int n,int i){
	//if val of i(column) is less than n, recursively print all the columns to the right
	//else if i(column) is equal to n, recursively print the row below..
	 if (n==0) return;
	 if (i<n)
	 {
	 	cout<<"* ";
	 	pattern1(n,i+1);
	 } else {
	 cout<<endl;
	 pattern1(n-1,0);
	}
}

int main(){
	int n;cin>>n;
//	cout<<fib(n)<<endl;
//	cout<<countPartyitems(n);
//	cout<<powerOptimisedRecursive(n,2);
	pattern1(n,0);
	return 0;

}