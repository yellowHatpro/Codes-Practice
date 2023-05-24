#include <bits/stdc++.h> 
using namespace std;
int main()
{
	vector<int> v{1, 2, 3, 4, 42, 1, 2};
	sort(v.begin(), v.end(), [](int a, int b)
		 { return a == b; });
	for (auto itr : v)
	{
		cout << itr << endl;
	}
vector<pair<int,int>> vp = {{1,2},{2,3}};
  auto [f,s] = vp[0];
	return 0;
}

