#include <bits/stdc++.h>
using namespace std;

class MyStack{
	//Two queues
	queue<int> q1, q2;
	int size;
public:
	MyStack(){
		size = 0;
	}
	void push(int x){
		size++;
		q2.push(x);
		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();
		}
		queue<int> tempq= q1;
		q1 = q2;
		q2 = tempq;
	}
	int pop(){
		if (q1.empty())
		{
			return -1;
		}
		int res = q1.front();
		q1.pop();
		size--;
		return res;
	}
	int top(){
		if (q1.empty())
		{
			return -1;
		}
		return q1.front();
	}
	bool empty(){
		return !size;
	}

};

