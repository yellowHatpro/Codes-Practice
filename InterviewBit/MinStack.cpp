#include <bits/stdc++.h>
using namespace std;


//This is O(2N) space solution, can be optimized to O(N) auxiliary space
class MinStack{
public:
	stack<pair<int,int>> s;
	MinStack();
	void push(int x);
	void pop();
	int top();
	int getMin();
};


MinStack::MinStack() {
		stack<pair<int,int>> s;

}

void MinStack::push(int x) {
	int mini;
	if (s.empty()){
		mini = x;
	} else {	
	mini = min(s.top().second, x);
	}
	s.push({x,mini});
}

void MinStack::pop() {
		if (s.empty()) return ;
	s.pop();
}

int MinStack::top() {
		if (s.empty()) return -1;
	return s.top().first;
}

int MinStack::getMin() {
	if (s.empty()) return -1;
	return s.top().second;
}

