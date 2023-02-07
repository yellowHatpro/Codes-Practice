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
#define pb push_back
#define endl "\n"
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define len(x) ((int) x.size())
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define mid(l,r) (l+(r-l)/2)
#define sortall(x) sort(all(x))
#define print(a) for(auto i: a) cout<<i<<" "; cout<<endl

//Type define
typedef pair<ll, ll> pll;
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
//Not so cool
void solve(){
	vector<vector<int>> v(2,vector<int>(2,0));
	int mini = INT_MAX;
	int maxi = INT_MIN;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
				cin>>v[i][j];
				mini = min(mini,v[i][j]);
				maxi = max(maxi,v[i][j]);
		}
	}
	if ((mini == v[0][1] && maxi == v[1][0] )||( mini == v[1][1] && maxi == v[0][0] ) ||( mini == v[1][0] && maxi == v[0][1] ) || (mini == v[0][0] && maxi == v[1][1]) ){
		YES
	} else {
		NO
	}

	return ;
}

//cool
void upsolve(){
	vector<int> a(4);
	for (int i = 0; i < 4; ++i)
	{
		cin>>a[i];
	}
	int maxpos = max_element(a.begin(),a.end()) - a.begin();
	int minpos = min_element(a.begin(),a.end()) - a.begin();
	if (maxpos + minpos ==3) YES
		else NO
	
}

int32_t main(){
	FIO
	int t=1;
	cin>>t;
	while(t--){
	upsolve();
	}
	return 0;
}
