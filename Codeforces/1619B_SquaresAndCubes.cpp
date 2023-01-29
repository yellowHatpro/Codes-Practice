// yellowhatpro
#include <bits/stdc++.h>
using namespace std;

//Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

//Constants
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9+7;

//Macros
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define F first
#define S second
#define mp map
#define ump unordered_map
#define pb emplace_back
#define ma make_pair
#define pii pair<ll,ll>
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define mid(l,r) (l+(r-l)/2)
#define sortall(x) sort(all(x))

//Type define
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef map<int, int> mii;


//Math Functions
ll LCM(int a, int b){
	return ((ll)a*b)/__gcd(a,b);
}

ll modpow(ll x, ll n, int m=MOD){
	if (x==0 && n==0) return 0; 
	ll res = 1;
	while(n>0){
		if (n%2){
			res = (res*x) %m;
		}
		x = (x*x)%m;
		n/=2;
	}
	return res;
}

void solve(){
	    int n;
        cin >> n;
        set<int> a;
        for (int i = 1; i * i <= n; i++)
            a.insert(i * i);
        for (int i = 1; i * i * i <= n; i++)
            a.insert(i * i * i);
        cout << a.size() << endl;
}

int main(){
	FIO
	int t=1;
	cin>>t;
	while(t--){
	solve();
	}
	return 0;
}
