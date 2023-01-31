// 2N+2 Numbers, 2 are unique
#include <bits/stdc++.h>
using namespace std;

int unique(vector<int> arr){
	int ans = arr[0];
	for (int i = 1; i < arr.size(); ++i)
	{
		ans^=arr[i];
	}
	int pos = 0;
	int temp = ans;
	while(temp&1==0){
		pos++;
		temp = temp>>1;
	}
	int mask =(1<<pos);
	int ans1 = 0;
	int ans2 = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		if ((mask&arr[i])>0){
			ans1^=arr[i];
		}
	}
	ans2=ans^ans1;
	cout<<ans1<<" "<<ans2<<endl;
}

int main(){
	vector<int> arr = {1,3,5,4,3,1,5,7};
	unique(arr);
	return 0;
}