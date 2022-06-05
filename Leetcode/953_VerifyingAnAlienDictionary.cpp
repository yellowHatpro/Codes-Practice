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