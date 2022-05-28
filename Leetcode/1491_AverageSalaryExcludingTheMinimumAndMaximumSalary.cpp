class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        double cnt = 0;
        for (int i = 1;i<salary.size()-1;i++){
            cnt+=salary[i];
        }
        return cnt/(salary.size()-2);
    }
};