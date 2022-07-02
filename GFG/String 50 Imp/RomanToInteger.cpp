#include <bits/stdc++.h>
using namespace std;

int romanToDecimal(string &str) {
	int cnt = 0;
      for (int i = 0; i < str.length(); ++i)
      {
      	if (str[i]=='M')
      	{
      		cnt+=1000;
      	}
      	else if (str[i]=='D'){
      		cnt+=500;
      	}
      	else if (str[i]=='V'){
      		cnt+=5;
      	}
      	else if (str[i]=='X'){
      		cnt+=10;
      	}
      	else if (str[i]=='C')
      	{
      		if (i!=str.length()-1)
      		{
      			if (str[i+1]=='D')
      				{
      					cnt+=400;
      					i++;
      				}
      			else if (str[i+1]=='M')
      			{
      				cnt+=900;
      				i++;
      			}
      			else{
      				cnt+=100;
      			}	
      		}else {
      			cnt+=100;
      		}
      	}
      	else if (str[i]=='X')
      	{
      		if (i!=str.length()-1)
      		{
      			if (str[i+1]=='L')
      				{
      					cnt+=40;
      					i++;
      				}
      			else if (str[i+1]=='C')
      			{
      				cnt+=90;
      				i++;
      			}
      			else{
      				cnt+=10;
      			}	
      		} else {
      			cnt+=10;
      		}
      	}
      	else if (str[i]=='I')
      	{
      		if (i!=str.length()-1)
      		{
      			if (str[i+1]=='V')
      				{
      					cnt+=4;
      					i++;
      				}
      			else if (str[i+1]=='X')
      			{
      				cnt+=9;
      				i++;
      			}
      			else{
      				cnt+=1;
      			}	
      		}else {
      			cnt+=1;
      		}
      	}
      }
      return cnt;
    }

int main(){
	
	return 0;
}