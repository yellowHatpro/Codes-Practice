#include<bits/stdc++.h>
using namespace std;
int main()
{char i{0},c;
  while(std::cin>>c&&i!=5)
    i+=c=="hello"[i];
  std::cout<<((i==5)?"YES":"NO");
}
