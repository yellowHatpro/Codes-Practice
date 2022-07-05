#include <bits/stdc++.h>
using namespace std;

bool isSorted(int a[], int size){
	if (size==0||size==1)
	{
		return true;
	}
	if (a[0]>a[1])
	{
		return false;
	}
	return isSorted(a+1,size-1);
}

int sum(int *input,  int n){
	if (n==0)
	{
		return 0;
	}
	return input[n-1] + sum(input+1,n-1);
}

bool checkNumber(int input[], int n, int x) {
	if (n==0)
	{
		return false;
	}
	if (input[n-1]==x)
	{
		return true;
	}
	return checkNumber(input,n-1,x);
}

//For the first index type questions we will move forward the pointer by 1 address and decrease the size as well
int firstIndex(int* input, int size, int x){
	if (size<=0)
	{
		return -1;
	}

	else if (input[0]==x)
	{ 
		return 0;
	}
	return firstIndex(input+1,size-1,x) == -1 ? -1: firstIndex(input+1,size-1,x)+1;
}

//For last index type question we will only decrease the size and we will use the decreased size value for indexing
int lastIndex(int* input, int size, int x){
	if (size<=0)
	{
		return -1;
	}
	if (input[size]==x)
	{
		return size;
	}
	return lastIndex(input,size-1,x);
}

int allIndexes(int* input, int size, int x, int (& output)[6]){
	if (size==0)
	{
		return 0;
	}
	int ans = allIndexes(input,size-1,x,output);
	if (input[size-1]==x)
	{	ans++;
		output[ans-1] = size-1;
	}
	return ans;
}


int main(){
	int arr[] = {1,2,5,4,5,5};
	int output[6]={-1,-1,-1,-1,-1,-1};
	int x = allIndexes(arr,6,5,output);
	cout<<x<<endl;
	for (int i = 0; i < 6; ++i)
	{
		cout<<output[i]<<" "<<endl;
	}
	return 0;
}