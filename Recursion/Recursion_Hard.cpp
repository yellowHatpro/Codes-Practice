#include <bits/stdc++.h>
using namespace std;

// From PepCoding, different from Sanket sir ones.


void printString(string str, string asf, int count, int pos){
	//base case
	if(pos==str.length()){
		if (count==0)
		{
			cout<<asf<<endl;
		}
		else{
			cout<<asf+to_string(count)<<endl;
		}
		return;
	}
	//Self Work
	if (count>0)
	{
		printString(str,asf+to_string(count)+str[pos],0,pos+1);
	}
	else{
		printString(str,asf+str[pos],0,pos+1);
	}
	printString(str,asf,count+1,pos+1);
}

int main(){
	string str; cin>>str;
	printString(str,"",0,0);
}