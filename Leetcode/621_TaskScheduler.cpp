#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    int counter[26] = {0};
    int maximum = 0;
    int maxCount = 0;
    for (char task : tasks) {
      counter[task - 'A']++;
      if (maximum == counter[task - 'A']) {
        maxCount++;
      } else if (maximum < counter[task - 'A']) {
        maximum = counter[task - 'A'];
        maxCount = 1;
      }
    }
    int partCount = maximum - 1;
    int partLength = n - (maxCount - 1);
    int emptySlots = partCount * partLength;
    int availableTasks = tasks.size() - maximum * maxCount;
    int idles = max(0, emptySlots - availableTasks);
    return tasks.size() + idles;
  }
};
