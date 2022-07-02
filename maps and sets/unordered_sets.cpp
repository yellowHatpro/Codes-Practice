#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	//Set is a collection of keys
	unordered_set<int> s{1,2,3,4,5};
	int key;cin>>key;
	if (s.find(key)!=s.end())
	{
		cout<<key<<" is present!"<<endl;
	}
	else {
		cout<<key<<" is not present"<<endl;
	}
	return 0;
}