#include <bits/stdc++.h>
using namespace std;

  void segregateElements(int arr[],int n)
    {
      vector<int> v1;
      vector<int> v2;
      for (int i = 0; i < n; ++i)
      {
      	if (arr[i]>=0)
      	{
      		v1.push_back(arr[i]);
      	}
      	else {
      		v2.push_back(arr[i]);
      	}
      }
      int k = v1.size();
      int l = v2.size();
      int m =0;
        for(int i=0;i<k;i++)
       arr[i]=v1[i];
       for(int i=k;i<k+l;i++)
       arr[i]=v2[m++];

    }

int main(){
	int arr[10] = {1,2,3,-1,1,-11,-111,-1,-1111,10};
	int n = 10;
	segregateElements(arr,n);
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}