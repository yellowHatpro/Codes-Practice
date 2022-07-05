#include <bits/stdc++.h>
using namespace std;

bool palindromeHelper(string input, int start, int end){
	if (start==end)
	{
		return true;
	}
	if (input[start]!=input[end])
	{
		return false;
	}

	if (start<end+1){
		return palindromeHelper(input,start+1, end-1);
	}

	return true;

}

bool checkPalindrome(string input){
	return palindromeHelper(input,0,input.length()-1);
}
int main(){
	string s = "malayalam";
	cout<<checkPalindrome(s)<<endl;
	return 0;
}