#include<bits/stdc++.h>
using namespace std;
template <typename T> 
class Stack{
public:
	int top_idx;
	T *array =new T;
	int numofele;

Stack(int cap){
	top_idx = -1;
	numofele=0;
}

void push(T data){
	top_idx++;
	numofele++;
	array[top_idx]=data;
}
T pop(){
	if(numofele==0){
		cout<<"Stack empty"<<endl;
		return -1;
	}
	T dlt = array[top_idx];
	delete (array+top_idx);
	top_idx--;
	numofele--;
	return dlt;
}
T top(){
	return array[top_idx];
}

bool isEmpty(){
	return numofele;
}
int size(){
	return numofele;
}

void display(){
	if (numofele==0){
		cout<<"Stack Empty"<<endl;
		return;
	}
	for (int i = 0; i < numofele; ++i)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

};
