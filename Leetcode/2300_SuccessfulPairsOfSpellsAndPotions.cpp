#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
         map<int, int> m;
         sort(potions.begin(), potions.end(), greater<int>());
         vector<int> v = spells;
         sort(spells.begin(), spells.end());
         int currPotion = 0;
         int currSpell = 0;
         while(currSpell<spells.size() && currPotion<potions.size()){
             long long mul =(long long) spells[currSpell]*potions[currPotion];
         	if ( mul <success){
         		m[spells[currSpell]] = currPotion;
         		currSpell++;
         	} else {
         		currPotion++;
         	}
         }
         while (currSpell<spells.size()){
             m[spells[currSpell++]] = currPotion;
         }
         vector<int> res;
         for (int i = 0; i < spells.size(); ++i)
         {
         	res.push_back(m[v[i]]);
         }
         return res;
    }
};