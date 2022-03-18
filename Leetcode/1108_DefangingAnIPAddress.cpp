#include <iostream>
using namespace std;
class Solution {
public:
    string defangIPaddr(string address) {
        string res ="";
        int i=0;
        while(i!=address.length()){
            if(address[i] !='.'){
                res+=address[i];
            }
            else{
                res+="[.]";
            }
            i++;
        }
        return res;

    }
};

class Solution{
    public:
    string defangIPaddr(string address){
        for(int i=0;i<address.size();i++){
            if(address[i]=='.'){
                address = address.substr(0,i)+"[.]"+address.substr(i+1);
                i+=2;
            }

        }
        return address;
    }
};