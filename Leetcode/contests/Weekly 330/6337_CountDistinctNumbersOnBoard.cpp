#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int distinctIntegers(int n) {
       int cnt = 0;
       queue<int> q;
       q.push(n);
       set<int> s;
       s.insert(n);
       cnt++;
       while(!q.empty()){
       	int x = q.front();
       	q.pop();
       	for (int i = 2; i < x; ++i)
       	{
       		if (x%i==1){
       			q.push(i);
       			s.insert(i);
       		}
       	}
       }
       return s.size();
   }
};