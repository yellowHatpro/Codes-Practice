#include <bits/stdc++.h>
using namespace std;


int* stockSpan(int *price, int size) {
	int* arr = new int[size];
	stack<int> s;
	for (int i = 0; i < size; ++i)
	{
		if (s.empty())
		{
			s.push(i);
			arr[i]=1;
		}else {
			if (price[s.top()]>=price[i])
			{
				s.push(i);
				arr[i] = 1;
			}
			else {
					int cnt=1;
			while(s.size()>=1 && price[s.top()]<price[i]){
				cnt+=arr[s.top()];
				s.pop();
				}
				arr[i] = cnt;
				s.push(i);
			}
		}
	}
	return arr;
}
