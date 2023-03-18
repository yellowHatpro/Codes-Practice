#include <bits/stdc++.h>
using namespace std;
class BrowserHistory {
public:
	stack<string> history, future;
	string current;

    BrowserHistory(string homepage) {
        current = homepage;
    }
    
    void visit(string url) {
        history.push(current);
        current = url;
        //we dont need future stack now, as mentioned in the question
        future = stack<string>();
    }
    
    string back(int steps) {
        while(steps-- && !history.empty()){
        	future.push(current);
        	current = history.top();
        	history.pop();
        }
        return current;
    }
    
    string forward(int steps) {
        while(steps-- && !future.empty()){
        	history.push(current);
        	current = future.top();
        	future.pop();
        }
        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */