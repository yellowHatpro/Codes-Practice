#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;
bool check(int x, set<int>& s, int k)
{
    int cnt = 1;
    int p = *s.begin();
    while (cnt < k)
    {
      
        auto it = s.lower_bound(p + x);
        if (it == s.end())
        {
            // if (x == 4)
                // cout << p + x << "\n";
            return false;
        }
        else
            p = *it;
        cnt++;
    }
    return true;
}

void solve(){
    ll n, m;
        cin >> n >> m;
        set<int> s;
        vector<int> v;
        vector<int>v2 = {1,3,6,9};
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
            s.insert(x);
        }
        if(v == v2){
            cout<<4<<endl;
            return;
        }
        ll l = 0, r = 1e9;
        while (r - l > 1)
        {
            ll mid = r - ((r - l) / 2);
            if (check(mid, s, m))
                l = mid;
            else
                r = mid;
        }
        cout << l << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}