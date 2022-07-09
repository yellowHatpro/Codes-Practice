#include <bits/stdc++.h>
using namespace std;
//Stack Using Array
class StackUsingArray{
int nextIndex;
int *data;
int capacity;

public:
	StackUsingArray(int size){
		data = new int[size];
		nextIndex = 0;
		capacity = size;
	}

	int size(){
		return nextIndex;
	}

	bool isEmpty() {
	return nextIndex==0;	
	}

	void push(int element){
		if (nextIndex==capacity)
		{
			cout<<"Stack Full"<<endl;
			return;
		}
		data[nextIndex++] = element;
	}

	int pop(){
		if (isEmpty())
		{
			cout<<"Stack Empty"<<endl;
			return INT_MIN;
		}
		nextIndex--;
		return data[nextIndex];
	}

	int top(){
		if (isEmpty())
		{
				cout<<"Stack Empty"<<endl;
				return INT_MIN;
		}
		return data[nextIndex-1];
	}

};