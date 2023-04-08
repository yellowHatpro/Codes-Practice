#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

	static bool comp(int a, int b){
		int cnta = bitset<32>(a).count();
		int cntb = bitset<32>(b).count();
		if (cnta==cntb) return a<=b;
		else return cnta<cntb;
	}

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};