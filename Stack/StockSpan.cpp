#include <bits/stdc++.h>
using namespace std;


int* stockSpan(int *price, int size) {
	int* arr = new int[size];
	stack<int> s;//s is containing index
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


int* stockSpanUsingNearestGreaterToLeft(int *price, int size){
	int* ans = new int[size]; // holds indexes
	stack<pair<int,int>> s; //holds NGL and its index
	for (int i = 0; i < size; ++i)
	{
		if (s.empty()){
			ans[i] = -1;
		} else if (s.size()>0 && s.top().first>price[i]){
			ans[i] = s.top().second;
		} else {
			while(s.size()>0 && s.top().first<=price[i]){
				s.pop();
			}
			if (s.size()>0){
				ans[i] = s.top().second;
			} else {
				ans[i] = -1;
			}
		}
		s.push({price[i],i});
	}
	for (int i = 0; i < size; ++i)
	{
		ans[i] = i-ans[i];
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int arr[] = {100,80,60,70,60,75,85,101};
	int size = 8;	
	int* res1 = stockSpan(arr,size);
	int* res2 = stockSpanUsingNearestGreaterToLeft(arr,size);
	for (int i = 0; i < size; ++i)
	{
		cout<<res1[i]<<endl;
	}
	cout<<" "<<endl;
	for (int i = 0; i < size; ++i)
	{
		cout<<res2[i]<<endl;
	}
	return 0;
}
