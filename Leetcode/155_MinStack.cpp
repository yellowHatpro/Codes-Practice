#include <bits/stdc++.h>
using namespace std;
class MinStack {
public:
	stack<pair<int,int>> s;
    MinStack() {
     	s = stack<pair<int,int>>();   
    }
    
    void push(int val) {
        int mini;
        if (s.empty()){
        	mini = val;
        }
        else {
        	mini = min(s.top().second, val);
        }
        s.push({val,mini});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};