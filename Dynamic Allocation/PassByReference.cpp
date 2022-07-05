#include <bits/stdc++.h>
using namespace std;


//Pass by reference
void increment(int& n){
	n++;
}

//We can also do return by reference
	//We need to be careful while returning address or reference of a local variable of a function, coz that memory will be cleared after the function has been used
//Bad practise
int& f1(int n){
	int i=n;
	return i;
}

//Bad practise
int* f2(){
	int i = 10;
	return &i;
}

void allIndexes(int (& x)[10]){
	//this is how we pass by reference any array, x is the array
}


int main(){

	//Reference variables can be made using & with the variables

	int i = 10;
	int &j = i; // j is a reference variable, no new memory allocated to j
	cout<<&i<<" "<<&j<<endl; //0x61ff08 0x61ff08

	i++;
	cout<<i<<" "<<j<<endl; //11 11

	//Reference variables need to be initialised on declaration
	/* int& j;
		j = i; ..this gives error
	*/
	increment(i);//this is how we pass as ref
	cout<<i<<endl;// will increment

	//This is not good practice
	int x = f1(i);
	int* y = f2();
	//Memory will be cleared of the address and reference of the local variable of the function, but we still are holding the memory, dont know what will be in that..

	return 0;
}