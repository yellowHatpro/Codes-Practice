// Using Stack to build Queue ends up in making either enqueue or dequeue a costier operation. 
// Achieved using 2 stacks (can be function call stack as well , recursion ;))

#include <bits/stdc++.h>
using namespace std;

class QueueUsingStack{

	stack<int> s1, s2;
public:
	//If I want to make enqueue a costier opeation, then
	void enqueue1(int data){
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(data);
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
	}

	void enqueue2(int data){
		s1.push(data);
		return;
	}

	int dequeue2(){
		if (s1.empty() && s2.empty()){
			cout<<"Queue is empty";
			exit(0);
		}
		//this is better
		if (s2.empty()){
				while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		}
	
		int top = s2.top();
		s2.pop();
		return top;
	}

	int dequeue1(){
		if (s1.empty()){
			cout<<"Underflow";
			exit(0);
		}
		int top = s1.top();
		s1.pop();
		return top;

	}

};