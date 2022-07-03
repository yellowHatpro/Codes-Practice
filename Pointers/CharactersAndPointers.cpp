#include <bits/stdc++.h>
using namespace std;

void swap (char **x, char **y) 
{
  char *t = *x;
  *x = *y;
  *y = t;
}


int main(){
	//Character Array 
	//Difference between character array and int array
	int a[] = {1,2,3};
	char c[] = "abc";
	//cout is implemented differently for character and int array
	cout<<a<<endl; // array address is printed
	cout<<"c "<<c<<endl; // array's actual content is printed
	cout<<"*c "<<*c<<endl; // prints the first character, just like array

	char* pc = &c[0];
	cout<<"pc "<< pc<<endl; // prints actual content, not address
	cout<<*pc<<endl;//This prints char
	
	//Things are weird when we are using character pointers
	char ch = 'a';
	char* pch = &ch;
	cout<<pch<<endl; // it will print the char 'a' and then continue printing stuff until it finds a null character

	char *x = "geeksquiz"; // char *x is essentially an array
	char *y = "geeksforgeeks";
    char *t;
    swap(x, y);
    cout<<x << " "<<y;

	return 0;
}