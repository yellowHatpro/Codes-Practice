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
#define pb push_back
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
typedef vector<ll> vll;
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

map<ll, ll> primeFactors(int n)
{
    // Print the number of 2s that divide n
    map<ll, ll> m;
    while (n % 2 == 0)
    {
        m[2]++;
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {	m[i]++;
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        m[n]++;
    return m;
}

void solve(){
	ll n;cin>>n;
	map<ll, ll> m =  primeFactors(n);
	vector<pair<ll,ll>> v;
	for (auto itr: m){
		v.push_back({itr.S, itr.F});
	}
	sort(v.begin(), v.end());
	
	map<int,vi> res;
	for (auto i: v)
	{
		res[i.F].push_back(i.S);
	}
	
	ll sum = 0;
	for (auto itr : res){
		ll cnn = 1;
		for(auto i: itr.S){
			cnn*=i;
		}
		sum+=(cnn*itr.F);
	}
	cout<<sum<<endl;
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
