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
#define int long long int
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

int isPresent(vector<int> v, int e){
	vector<int>::iterator itr;
	itr = find(v.begin(), v.end(), e);
	if (itr!=v.end()){
		return itr - v.begin();
	} else return -1;
}

void solve(){
	int n,m;cin>>n>>m;
	set<int> ra;
	for (int i = 0; i < m; ++i)
	{
		int x;cin>>x;
	}
	vector<int> res;
	map<int, int> mi;
	for (int i = 0; i < n; ++i)
	{
		res.push_back(i+1);
		mi[i+1] = -1;
	}
	for (int i = 0; i < m; ++i)
	{
		if (ra[i]>n){
			if (res[n-1]<=n) mi[res[res.size()-1]] = i+1;
			res.pop_back();
			res.insert(res.begin(),ra[i]);
		}
		else{
			int x = res[isPresent(res, ra[i])];
			res.erase(res.begin()+isPresent(res, ra[i]));
			res.insert(res.begin(), ra[i]);
		}
	}
	for (auto itr: mi){
		cout<<itr.S<<" ";
	}
	cout<<endl;
	return;

}

int32_t main(){
	FIO
	int t=1;
	cin>>t;
	while(t--){
	solve();
	}
	return 0;
}
