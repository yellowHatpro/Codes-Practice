#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> s;
    StockSpanner() {
    }
    
    int next(int price) {
      if (s.empty()) {
        s.push({price,1});
        return 1;
    }
      else if (price<s.top().first){
        s.push({price,1});
        return 1;
    } else {
        int cnt = 1;
        while(!s.empty() && s.top().first<=price){
          cnt+=s.top().second;
          s.pop();
      }
        s.push({price,cnt});
        return cnt;
    }
  }
};

