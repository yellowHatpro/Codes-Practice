//
// Created by ashu on 26-04-2022.
//
/*
arr[] =  {2, 5, 8, 4, 6, 11}, sum = 13
Output :
5 8
2 11
2 5 6
*/
#include <bits/stdc++.h>
using namespace std;

void subsetsSumK(vector<int> v, int n, vector<int> v2, int sum) {
    if (sum == 0) {
        for (auto x: v2) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    //No more elements to add
    if (n == 0) {
        return;
    }
    //Don't add last element
    subsetsSumK(v, n - 1, v2,sum);
    v2.push_back(v[n - 1]);
    //Include last element
    subsetsSumK(v,n - 1, v2,sum-v[n-1]);
}

void subsetSumKBacktracking(vector<int> v, int n, vector<int> v2, int sum){
    if(sum == 0){
        for(auto x: v2){
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    if(n == 0){
        return;
    }
    subsetSumKBacktracking(v,n-1,v2,sum);
    v2.push_back(v[n-1]);
    subsetSumKBacktracking(v,n-1,v2,sum-v[n-1]);
}

void printAllSubsets(vector<int> v, int n, int sum)
{
    vector<int> v2;
    subsetsSumK(v, n, v2, sum);
}

int main(){
    vector<int> v = {2, 5, 8, 4, 6, 11};
    int n = v.size();
    int sum = 13;
    printAllSubsets(v, n, sum);
    return 0;
}


