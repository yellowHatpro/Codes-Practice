class Solution {
public:
bool areAlmostEqual(string s1, string s2) {
    int count = 0;
    char a,s;
    
    for(int i=0; i<s1.length(); i++){
        if(s1[i] != s2[i]){
            if(count == 2 || (count == 1 && (s1[i] != s || s2[i] != a)) )
                return false;
            else
                a = s1[i];
                s = s2[i];
            count++;
        }
    }
    if(count == 1)
        return false;
    return true;
  }
};
