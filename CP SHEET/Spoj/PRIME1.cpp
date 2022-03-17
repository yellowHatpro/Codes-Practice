#include "bits/stdc++.h"
using namespace std;

vector<bool> segmentedSieveNoPreGen(long long L, long long R) {
    vector<bool> isPrime(R - L + 1, true);
    long long lim = sqrt(R);
    for (long long i = 2; i <= lim; ++i)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}


int main(){
	int t;cin>>t;
	while(t--){
		long long m;
		long long n;
		cin>>m>>n;
		vector<bool> isPrime;
		isPrime = segmentedSieveNoPreGen(m,n);
		for (int i = 0; i < isPrime.size(); ++i)
		{	
			if (isPrime[i])
			{
				cout<<m+i<<endl;
			}
			
		}
		cout<<""<<endl;

	}
}