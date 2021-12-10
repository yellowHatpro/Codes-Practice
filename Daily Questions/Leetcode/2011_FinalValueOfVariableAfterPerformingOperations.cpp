#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(int i=0;i<operations.size();i++){
            if (operations[i]=="X++"|| operations[i]=="++X"){
                x++;
            }
            else{
                x--;
            }
        }
        return x;
    }
};

//Another Solution
class Solution {
    public:
        int finalValueAfterOperations(vector<string>& operations){
            int x =0;
            for(auto itr:operations){
                x+=itr[1]=='+'?1:-1;
            }
            return x;
        }
    };