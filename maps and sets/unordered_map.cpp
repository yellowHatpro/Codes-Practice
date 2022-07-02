#include <iostream>
#include <unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
	unordered_map<string,int> menu;
	menu["maggi"] = 115;
	menu["colddrink"] = 11;
	menu["dosa"] = 55;
	string item;
	cin>>item; 
	if (menu.count(item)==0)
	{
		cout<<item<<" is not available"<<endl;
	}else {
		cout<<item<< " is available, and its cost is"<<menu[item]<<endl;
	}
	return 0;
}