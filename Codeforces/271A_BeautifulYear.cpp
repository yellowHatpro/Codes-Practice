#include <bits/stdc++.h>
using namespace std;
bool solve(int num){
	int w = num/1000;
	int x = num/100;
		x%=10;
	int y = num/10;
		y%=10;
	int z = num%10;
	if(w!=x&&x!=y&&y!=z&&z!=w&&w!=y&&x!=z){
		return true;
	}	
	else{
		return false;
	}
}
int main(){
	int num;cin>>num;
	int cnt = num+1;
	while(true){
		if (!solve(cnt))
		{
			cnt++;
		}
		else{
			cout<<cnt;
			return 0;
		}
	}
	cout<<endl;	
	return 0;
}