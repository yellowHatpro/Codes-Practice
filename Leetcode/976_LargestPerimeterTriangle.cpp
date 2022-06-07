#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int n = arr.size();
        int maxx = 0;
        int i=0 , j=0;
        vector<int> temp;
        while(j<n){
            if(j-i+1<3){
                temp.push_back(arr[j]);
                j++;
            }
            else if(j-i+1==3){
                temp.push_back(arr[j]);
                j++;
                if(temp[0]+temp[1]>temp[2]){
                    maxx = max(maxx , temp[0]+temp[1]+temp[2]) ;
                }
                temp.erase(temp.begin());
                i++;
            }
        }
        return maxx;
    }
};