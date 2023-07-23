#include <bits/stdc++.h>
using namespace std;

class Queue {

	int front, rear;
	vector<int> arr;

public:
	Queue()
	{
		front = 0;
		rear = 0;
		arr.resize(100001);
	}

	void enqueue(int e)
	{
    if (rear==arr.size()){
      arr.resize(arr.size()*2);
    }
    arr[rear++] = e;
	}

	int dequeue()
	{
    if (front==rear){
      arr.clear();
      front = 0;
      rear = 0;
      return -1;
    }
    int ans = arr[front];
    front++;
    return ans;
	}
};
