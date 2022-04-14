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

void countNonConsequetive1BinStrings(int i, int n, string curr){
	if(i==n){
		cout<<curr<<endl;
		return;
	}
	if(curr[curr.length()-1]=='1'){
			countNonConsequetive1BinStrings(i+1,n,curr+'0');
			
	}
	else{
	countNonConsequetive1BinStrings(i+1,n,curr+'0');
	countNonConsequetive1BinStrings(i+1,n,curr+'1');
	}
	
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

void pattern2(int n,int i){
	if (n==0) return;
	if (i>0)
	{	cout<<"* ";
		pattern2(n,i-1);
	}else{
	cout<<endl;
	pattern2(n-1,n-1);
		}
	}

//Q4. Given an array, print all the subsets of the array.
void printAllSubsets(vector<int> v, int i, int n, string curr){
	//Base Case
	if(i==n){
		cout<<"["<<curr<<"]\n";
		return;
	}
	printAllSubsets(v,i+1,n,curr+to_string(v[i])+" ");
	printAllSubsets(v,i+1,n,curr);
}

//Q5. Given an array, tell if it is sorted
void sortedOrNot(vector<int> v, int i, int n){
	if (i==n)
	{
		cout<<"TRUE";
		return ;
	}
	if (v[i]>v[i+1])
	{
		cout<<"FALSE";
		return;}
	
	else {
				sortedOrNot(v,i+1,n);

	}
}	



//--------------🅜🅐🅘🅝 🅕🅤🅝🅒🅣🅘🅞🅝 🅗🅔🅡🅔------------------------//
int main(){
	int n;cin>>n;
//	cout<<fib(n)<<endl;
//	cout<<countPartyitems(n);
//	cout<<powerOptimisedRecursive(n,2);
//	pattern2(n,n);
//	printAllSubsets({1,2,3,4},0,4,"");
//	countNonConsequetive1BinStrings(0,3,"");
	sortedOrNot({1,2,3,1,4},0,5);
	return 0;

}