#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int last101 = -1;
        int last102 = -1;
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < player2.size(); i++){
        	if (last101!=-1 && (i-last101==1 || i - last101 == 2)){
        		sum1+=2*player1[i];
        	}
        	else {
        		sum1+=(player1[i]);
        	}
        	if (last102!=-1 &&( i-last102==1 || i - last102 == 2)){
        		sum2+=2*player2[i];
        	}
        	else {
        		sum2+=(player2[i]);
        	}
        	if (player1[i]==10){
        		last101 = i;
        	}
        	if (player2[i]==10){
        		last102 = i;
        	}
        }
        if (sum1>sum2){
        	return 1;
        } else if (sum2>sum1){
        	return 2;
        }
        return 0;
    }
};