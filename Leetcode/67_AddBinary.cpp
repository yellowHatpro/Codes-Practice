class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int carry=0;
        int i=a.size()-1,j=b.size()-1;
        while(i>=0 and j>=0){
            int sum=a[i--]-'0'+b[j--]-'0'+carry;
            carry=sum/2;
            sum%=2;
            ans.push_back(sum+'0');
        }
        while(i>=0){
            int sum=a[i--]-'0'+carry;
            carry=sum/2;
            sum%=2;
            ans.push_back(sum+'0');
        }
        while(j>=0){
            int sum=b[j--]-'0'+carry;
            carry=sum/2;
            sum%=2;
            ans.push_back(sum+'0');
        }
        if(carry!=0){
            ans.push_back(carry+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};