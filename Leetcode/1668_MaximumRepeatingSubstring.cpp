class Solution {
public:
    void precompute(vector<int>&lps,string&pat){
        int m=pat.length(),i=1,j=0;
        lps[0]=0;
        while(i<m){
            if(pat[i]==pat[j]){
                lps[i]=j+1;
                i++;
                j++;
            }
            else{
                if(j!=0){j=lps[j-1];}
                else{lps[i]=0;i++;}
            }
        }
        return ;
    }
    
    int kmp(string&txt,string &pat,int l){
        int n=txt.length(),m=pat.length(),i=0,j=0;
        vector<int>lps(m);
        precompute(lps,pat);
        int ans=0;
        while(i<n){
            if(txt[i]==pat[j]){
                i++;
                j++;
            }
            else{
                if(j!=0){j=lps[j-1];}
                else{i++;}
            }
            if(j%l==0){
                ans=max(ans,j/l);
            }
        }
        return ans;
    }
    
    int maxRepeating(string &sequence, string &word) {
        int n=sequence.length();
        int m=word.length();
        if(n<m){return 0;}
        int possible=n/m;
        string pat="";
        for(int i=0;i<possible;i++){
            pat+=word;
        }
        //cout<<word<<endl;
        return kmp(sequence,pat,m);
        return 0;
    }
};