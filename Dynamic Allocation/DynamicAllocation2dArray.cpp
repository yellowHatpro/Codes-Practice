#include <bits/stdc++.h>
using namespace std;
int main(){
	//We gonna make a[10][10] dynamically
	int** a = new int*[10];
	for (int i = 0; i < 10; ++i)
	{
		a[i] = new int[10];
	}

	//deallocation
	for (int i = 0; i < 10; ++i)
	{
		delete [] a[i];
	}
	delete [] a;
	return 0;
}