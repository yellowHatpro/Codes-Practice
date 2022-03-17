/*Q. Given n number of coordinates , task is to find number of sides in the polygon.
Input in sequential form.
Constraints : 2< n <=10
Input:
5
0 0 
0 3
3 3
3 1
3 0

Output:
4
*/

#include <bits/stdc++.h>
using namespace std;

class Pair{
public:
	int x;
	int y;
	Pair(int x, int y){
		this->x=x;
		this->y=y;
	}
	printPair(){
		cout<<x<<" "<<y;
		cout<<endl;
	}
};

double slope(int x1,int y1, int x2, int y2){
	 return double(abs((y2-y1)))/double(abs((x2-x1)));
}

int main(){
	int n;cin>>n;
	int count=1;
	vector<Pair> v;
	vector<double> slopes;
	for (int i = 0; i < n; ++i){
		int x;
		int y;
		cin>>x;
		cin>>y;
		Pair p(x,y);
		v.push_back(p);
	}
	for (int i=0; i <n-1; i++){
		slopes.push_back(slope(v[i].x,v[i].y,v[i+1].x,v[i+1].y));	
	}
	slopes.push_back(slope(v[0].x,v[0].y,v[n-1].x,v[n-1].y));
	for (int i = 0; i < slopes.size()-1; ++i){
		if (slopes[i]!=slopes[i+1]){
			count++;
		}
	}
	cout<<count;
	
}
