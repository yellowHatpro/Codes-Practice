#include <bits/stdc++.h>
using namespace std;
int main(){

	//Creating dynamically allocated variable
	//Step 1: Create a new int and store its address in the pointer
	int* ptr = new int;

	//Step 2: Deference the pointer and set the variable's value
	*ptr = 10;

	cout<<*ptr<<endl;

	//The pointer variable will be stored in the stack memory, 8 bytes allocated there
	//The memory we allocated in the heap by using "new" keyword is also there, taking 4 bytes in the heap

	double* dptr = new double;
	char* cptr = new char;

	//Allocations for arrays: we store the address of first element
	int* arr = new int[10];
	int n;cin>>n;
	int* arr2 = new int[n];
	arr2[2] = 10;//*(pa2+2)

	//Dynamic memory manual release is required..
	delete ptr;//for single element
	delete []arr2;//for array
	//pointer wont get deleted, coz it is statically allocated,but memory allocated by new keyword is deleted
	return 0;
}