#include <queue>
void reverseQueue(queue<int> &q) {
	// Write your code here
    if (q.empty())
     {
         return;
     } 
     int x = q.front();
     q.pop();
     reverseQueue(q);
     q.push(x);
}
