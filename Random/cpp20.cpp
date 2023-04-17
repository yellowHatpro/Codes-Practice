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
	return 0;
}