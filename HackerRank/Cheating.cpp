#include <bits/stdc++.h>
using namespace std;

string longestEvenWord(string s){
	map<int, pair<int,int>> m;
	stringstream ss(s);
	// we can read and write data on this buffer 
	string token;
	vector<string> tokens;
	while(getline(ss,token, ' ')){
		tokens.push_back(token);
	}
	int idx = -1;
	int maxSize = 0;
	for (int i = 0; i<tokens.size(); i++){
		if (tokens[i].size()%2==0){
			if (maxSize==tokens[i].size()){
				continue;
			} else if (tokens[i].size()>maxSize){
				idx = i;
				maxSize = tokens[i].size();
			}
		}
	}
	return  (idx!= -1 ) ? tokens[idx] : "00";
}

int main(){
	string s = "heynjnb";
	cout<<longestEvenWord(s)<<endl;
	return 0;
}