#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  // If asked kthMin -> use maxHeap (default in cpp)
  //  If asked kthMax -> use minHeap
  int kthSmallest(int arr[], int l, int r, int k) {
    priority_queue<int> q;
    for (int i = l; i <= r; ++i) {
      q.push(arr[i]);
      if (q.size() > k)
        q.pop(); // Maintain size k, and pop if size > k
    }
    return q.top();
  }
};
