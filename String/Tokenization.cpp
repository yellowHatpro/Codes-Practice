//String Tokenization
//input: "today is a sunny day"
//output: "today","is", "a", "sunny", "day"
//stringstream class
#include <bits/stdc++.h>
using namespace std;
int main(){
	string input;
	getline(cin, input);

	//create a stringstream object
	stringstream ss(input);
	// we can read and write data on this buffer 
	string token;
	vector<string> tokens;
	while(getline(ss,token, ' ')){
		tokens.push_back(token);
	}
	for (auto itr: tokens){
		cout << itr<<endl;
	}
	return 0;
}
