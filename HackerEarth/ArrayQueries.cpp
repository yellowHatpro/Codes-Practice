#include<bits/stdc++.h>
#define MOD 998244353
#define ll long long
using namespace std;


int fab(vector<int> a, vector<int> b, int n, int m){
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			ans +=(a[i]*b[j]*(i+2+j));
		}
	}
	return (int)ans%MOD;
}


vector<int> array_queries (int N, int M, vector<int> A, vector<int> B, int Q, vector<vector<int> > queries) {
	vector<int> res;

	res.push_back(fab(A,B,N,M));

   for (int i = 0; i < Q; ++i)
   {
   		if (queries[i][0]==1){
   			swap(A[queries[i][1]-1],B[queries[i][2]-1]);
   		}
   		else if (queries[i][0]==2){
   			swap(A[queries[i][1]-1],A[queries[i][2]-1]);
   		}
   		else if (queries[i][0]==3){
   			swap(B[queries[i][1]-1],B[queries[i][2]-1]);
   		}
   		res.push_back(fab(A,B,N,M));
   }
   return res;
   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int M;
        cin >> M;
        vector<int> A(N);
        for(int i_A = 0; i_A < N; i_A++)
        {
        	cin >> A[i_A];
        }
        vector<int> B(M);
        for(int i_B = 0; i_B < M; i_B++)
        {
        	cin >> B[i_B];
        }
        int Q;
        cin >> Q;
        vector<vector<int> > queries(Q, vector<int>(3));
        for (int i_queries = 0; i_queries < Q; i_queries++)
        {
        	for(int j_queries = 0; j_queries < 3; j_queries++)
        	{
        		cin >> queries[i_queries][j_queries];
        	}
        }

        vector<int> out_;
        out_ = array_queries(N, M, A, B, Q, queries);
        cout << out_[0];
        for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
        {
        	cout << " " << out_[i_out_];
        }
        cout << "\n";
    }
}