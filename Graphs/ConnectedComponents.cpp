#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    vector<int> visited(10,0);
    int cnt = 0;
    for (int i = 0; i < visited.size(); i++)
    {
        if (!visited[i]){
            //BFS or DFS
            cnt++;
        }
    }

    cout<<"Connected components : "<<cnt<<endl;
    
      
    return 0;
}