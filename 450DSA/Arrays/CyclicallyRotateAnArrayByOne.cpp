#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n)
{
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
    	v.push_back(arr[i]);
    }
    reverse(v.begin(), v.begin()+(n-1));
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; ++i)
    {
    	arr[i] = v[i];
    }
}