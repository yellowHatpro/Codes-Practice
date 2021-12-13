#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;


// task-0, 1, 2
int f(int day, int task , vi &a, vi &b, vi &c)
{
    // Base Case
    if (day == 0)
    {
        if (task == 0)
            return a[day];
        return (task == 1) ? b[day] : c[day]; 
    }
    
    if (task == 0)
    {
        int ans1 = f(day - 1, 1, a, b, c) + b[day];
        int ans2 = f(day - 1, 2, a, b, c) + c[day];

        return max(ans1, ans2);
    }

    if (task == 1)
    {
        int ans1 = f(day - 1, 0, a, b, c) + a[day];
        int ans2 = f(day - 1, 2, a, b, c) + c[day];

        return max(ans1, ans2);
    }
    if (task == 2)
    {
        int ans1 = f(day - 1, 1, a, b, c) + b[day];
        int ans2 = f(day - 1, 0, a, b, c) + a[day];

        return max(ans1, ans2);
    }

    return 0;
}

int main()
{
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);

    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];
    
    int ans = max({f(n - 1, 0, a, b, c), f(n - 1, 1, a, b, c), f(n - 1, 2, a, b, c)});
    cout << ans << "\n";
    return 0;
}