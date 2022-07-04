#include <bits/stdc++.h>
using namespace std;
int main(){
	

	int i = 65;
	cout<<"address of i "<<&i<<endl;
	char c = i;
	cout<<c<<endl;

	int* p = &i;
	char* pc = (char*)p;
	cout<<*pc<<endl; //Little Endian system

	cout<<p<<endl; // address of i
	cout<<pc<<endl;// prints actual content on going to the address and then prints till it finds a null character. 




	return 0;
}