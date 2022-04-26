#include <bits/stdc++.h>
using namespace std;

vector<int> subset, in;
int k;
void get(int i)
{
// to get the sum of the vector
int tot = accumulate(subset.begin(), subset.end(), 0ll);
if (tot > k)
return;
else if (tot == k)
{
for (auto p : subset)
cout << p << ' ';
cout << endl;
return;
}
if (i == in.size())
return;
subset.push_back(in[i]);
get(i + 1);
subset.pop_back();
get(i + 1);
return;
}
int32_t main()

{
int n;
cin >> n;
cin >> k;
in = vector<int>(n);
for (auto &p : in)
cin >> p;
get(0);
return 0;
}