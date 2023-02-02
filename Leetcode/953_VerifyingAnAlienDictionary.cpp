#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int order(char c,string ord){
        for(int i=0;i<ord.size();i++){
            if(ord[i]==c)return i;
        }
        return -1;
    }
    
    bool isAlienSorted(vector<string>& words, string ord) {
        for(int i=0;i<words.size()-1;i++){
            
            if(order(words[i][0],ord)>order(words[i+1][0],ord))return false;
            
            else if(order(words[i][0],ord)==order(words[i+1][0],ord)){
                int f=0;
                int p=min(words[i].size(),words[i+1].size());
                for(int j=1;j<p;j++){
                    if(order(words[i][j],ord)>order(words[i+1][j],ord)){
                        return false;
                    }
                }
                for(int j=1;j<p;j++){
                    if(order(words[i][j],ord)!=order(words[i+1][j],ord)){
                        f=1;
                        break;
                    }
                }
                if(f==0){
                    if(words[i].size()>words[i+1].size())return false;
                }
            }
           else{
               continue;
           } 
            
        }
        return true;
    }
};

class Solution2 {
public:
    bool isAlienSorted(vector<string>& words, string order) {
     map<char,int> o;
     for (int i = 0; i < order.size(); ++i)
        {
            o[order[i]]=i+1;
        }
     for (int i = 1; i < words.size(); ++i)
        {
            int j=0;
            int k =0;
            bool ok = false;
            while(j<words[i-1].size()&&k<words[i].size()){
                if (o[words[i-1][j]]<o[words[i][k]]){
                    ok = true;
                    break;
                }
                else if (o[words[i-1][j]]==o[words[i][k]]){
                    j++;k++;
                } else {
                    return false;
                }
            }
            if (j<words[i-1].size() && !ok){
                return false;
            }
        }
        return true;   
    }
};