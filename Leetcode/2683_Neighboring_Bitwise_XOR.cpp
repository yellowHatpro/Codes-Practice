#include<bits/stdc++.h>

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int first = derived[0];
        int prev = derived[0];
        for (int i = 0; i < derived.size()-1; i++) {
            if (derived[i]==1){
               prev =~ prev;
            } else {
                prev = prev;
            }
        }
        if (derived[derived.size()-1]==1){
            if (prev==first){
                return false;
            } else{
                return true;
            }
        } else {
            if (prev==first){
                return true;
            } else {
                return false;
            }
        }
        
    }
};
