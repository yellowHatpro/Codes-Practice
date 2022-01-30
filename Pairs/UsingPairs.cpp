#include <bits/stdc++.h>
#include "Pairs.cpp"
using namespace std;

int main(){
	Pair<int> p1;
	p1.setX(10);
	p1.setY(20);
	cout<<p1.getX() <<" "<<p1.getY()<<endl;
	Pair<double> p2;
	p2.setX(10000.3442);
	p2.setY(1002323.242);
	cout<<p2.getX()<<" "<<p2.getY()<<endl;

	MultiTypePair<int,float> p3;
	p3.setX(100);
	p3.setY(3.14);
	cout<<p3.getX()<<" "<<p3.getY()<<endl;

	MultiTypePair<MultiTypePair<int,int>, int> tooMuchPairs;
	tooMuchPairs.setY(10);
	MultiTypePair<int,int> innerPair;
	innerPair.setX(20);
	innerPair.setY(30);
	tooMuchPairs.setX(innerPair);
	cout<<tooMuchPairs.getX().getX()<<" "<<tooMuchPairs.getX().getY()<<" "<<tooMuchPairs.getY()<<endl;
}