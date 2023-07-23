#include <bits/stdc++.h>
using namespace std;

// Stack class.
class Stack {
    
vector<int> v;
int topEle;
int size;
public:
    
    Stack(int capacity) {
        v.clear();
        v.resize(capacity);
        size = capacity;
        topEle = -1;
    }

    void push(int num) {
        if (!isFull()){
        v[++topEle] = num;
      }
    }

    int pop() {
        if (isEmpty()) return -1;
        int topElement = v[topEle];
        topEle--;
        return topElement;
    }
    
    int top() {
      if (topEle==-1) return -1;
      return v[topEle];
    }
    
    int isEmpty() {
      return topEle==-1;
    }
    
    int isFull() {
        return topEle==(v.size()-1);
    }
    
};

