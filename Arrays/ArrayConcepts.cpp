#include <bits/stdc++.h>
using namespace std;



int main(){

//1. Initialising array
int size = 1000;
int arr[size] = {}; // initialises array with 0

//Universal  Initialization of array:

int foo[] = {1,2,3,4};
int foo2[] {1,2,3,4};  //Both are same

//

cout<<endl;
	return 0;
}

//Sort an array
//sort(arr,arr+n);

//Passing Array to function : Passed  as a pointer to the first element.


void process (int *p, const size_t len){
	//This method is  passes the original array, not copy.
	//Because the array parameter is not const, the function can modify the array elements.

}