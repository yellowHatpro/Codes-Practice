#include <bits/stdc++.h>
using namespace std;
int main(){
	int i=10;
	cout<<&i<<endl;
	int* p = &i; //0x61ff0c
	cout<<"address of p "<<&p<<endl;//address of p
	cout<<"address of i "<<p<<endl;
	cout<<"content of i "<<*p<<endl;//content of i-> 10
	//p=p-1; 
	cout<<"address of i "<<p<<endl;//4 memory location back, size of an integer

	//This increment decrement makes sense in case of arrays, since the data structure is contiguous memory allocation of same type of data type.

	int a[10]={1,2,3,4,5,6,7,8,9,10}; //array
	cout<<"a "<<a<<endl; // a is same as &a[0]
	cout<<"&a "<<&a<<endl;
	int* ptr = a;
	cout<<"A pointer ptr's address pointing to the array "<<&ptr<<endl;//Stored somewhere else
	cout<<"&a[0] "<<&a[0]<<endl;
	//a and &a &a[0] points to address of array's 0th element

	cout<<*a<<endl;
	cout<<*(a+1)<<endl; //effectively a[1]
	cout<<2[a]<<endl; //i[a] = a[i] = *(a+i)

	cout<<sizeof(a)<<endl;
	cout<<sizeof(ptr)<<endl;

	//We can do
	p = p+1;
	p = a+1;
	//We can't do a = a+1, array types are not re assignable


//We cannot assign a  pointer to array, but can assign an array to the pointer.



	return 0;

}