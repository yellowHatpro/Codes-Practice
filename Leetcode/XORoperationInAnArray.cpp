class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> v;
        int res=0;
        for(int i=0;i<n;i++){
            v.push_back(start+(2*i));
        }
        res=v[0];
        for(int i=1;i<n;i++){
            res^=v[i];
        }
        return res;
    }
};