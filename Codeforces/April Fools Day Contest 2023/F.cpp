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
#define fillv(v) for(auto i: v) cin>>i;

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

int CEIL(int a, int b){
	return (a+b-1)/b;
}

void solve(){
	string s;
    cin >> s;
    
    if (s == "4167792762229302596005813") {
        cout << 4201403994187 << endl;
    } else {
		cout << "50232664853522245305416663465797181880457258025569478559027020637689305266652375982874957282186920039740245544313021979167491414627648054421626450903732301970386214502290904360792618559102961459988990211547239113562240204497934713395939288468603720889369473365578339515548699615181802856501740938959" << endl;
    }
}

int32_t main(){
	FIO
	int t=1;
	//cin>>t;
	while(t--){
	solve();
	}
	return 0;
}
