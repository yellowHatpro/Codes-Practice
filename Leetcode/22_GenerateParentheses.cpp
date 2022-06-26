class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string curr="";
        help(n,0,0,res,curr);
        return res;
    }
    
    void help(int n, int open, int close, vector<string> &res, string &curr)
    {
        if(curr.size()==2*n)
        {
            res.push_back(curr);
            return;
        }
        if(open<n)
        {
            curr.push_back('(');
            help(n,open+1,close,res,curr);
            curr.pop_back();
        }
        if(close<open)
        {
            curr.push_back(')');
            help(n,open,close+1,res,curr);
            curr.pop_back();
        }
    }
};