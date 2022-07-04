#include <bits/stdc++.h>
using namespace std;


/*Inline functions: 
It gives performance boost to the function, it replaces the function used in the main body with the body inside this function body
We cant make each function inline because it makes a.out file bulky and compiler wont do big functions inline, it depends on compiler
*/
inline int max(int a,int b){
	return (a>b)?a:b;
	//ternary operator
	//(condition)?(if true then):(else do this)
}
int main(){
	int a,b;
	cin>>a>>b;
	int c;
	if (a>b)
	{
		c=a;
	}else {
		c=b;
	}

	return 0;
}