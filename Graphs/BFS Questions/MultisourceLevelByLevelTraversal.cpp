/* Q. Given a matrix , m*n dimension , 
0-> empty cell ,
1->fresh fruit,
2->rotten fruit
Determine the min time required to rot all the fruit given the condition a rotten fruit affects the fruit at its adjacent cells (up ,down ,left ,right).
In one unit time , you affect only the neighbours.
2 1 0 2 1
1 0 1 2 1
1 0 0 2 1
Answer is 2 unit time.
MULTISOURCE LEVEL BY LEVEL TRAVERSAL
This problem is a typical example of MULTISOURCE  BFS.
That is , Multiple starting point in BFS.
Add all the rotten fruit to the queue.
Then start the normal BFS.
Overall time complexity will be : m x n

-͋̔̅̕-͆͌̅͝-͌͐̅͝-̓͐̅-̿͌̅͝-̈́͌̅͝-͒͛̓̅-̈́̅̕-̽͑̓̅-͑̽̅͝-͌͋̾̅-͊̅͝͠-͊̅̕͝-͒̒͊̅-͆͛͌̅-̽̈́͛̅-͌̅̕̚-̐͌̒̅-͆̀̅͝-̐͛̅̕-̓̀̅͠-̅̚͝͝-́̿̿̅-̐́̅͘-͌̿͊̅-͋̅̕͝-͌̔̓̅-́̾̒̅-͋̾̓̅-̈́̽̅͝-̈́͛͌̅-̈́́̿̅-͒̾̓̅-̀͐̽̅-͌͌̅͠-͊̅͝͝-͒̈́̅͠-̐̅̕͠-͋̾͒̅-͑́͒̅-͒͌̅͠-͆̾̒̅-̾̒̈́̅-̅͘͝͝-͑̾̅͘-̈́̾̅͝-̒͑̅͠-̐̓̅-̓̾̅̕-̽̅͘-͑͊̓̅-̈́̀̅-͆̒̔̅-̾̾̒̅-͒͌̈́̅-̓͆̈́̅-̿͒̅-̾́̅͠-͊̒̅͘-̈́͆̈́̅-͋̔̅̕-͆͌̅͝-͌͐̅͝-̓͐̅-̿͌̅͝-̈́͌̅͝-͒͛̓̅-̈́̅̕-̽͑̓̅-͑̽̅͝-͌͋̾̅-͊̅͝͠-͊̅̕͝-͒̒͊̅-͆͛͌̅-̽̈́͛̅-͌̅̕̚-̐͌̒̅-͆̀̅͝-̐͛̅̕-̓̀̅͠-̅̚͝͝-́̿̿̅-̐́̅͘-͌̿͊̅-͋̅̕͝-͌̔̓̅-́̾̒̅-͋̾̓̅-̈́̽̅͝-̈́͛͌̅-̈́́̿̅-͒̾̓̅-̀͐̽̅-͌͌̅͠-͊̅͝͝-͒̈́̅͠-̐̅̕͠-͋̾͒̅-͑́͒̅-͒͌̅͠-͆̾̒̅-̾̒̈́̅-̅͘͝͝-͑̾̅͘-̈́̾̅͝-̒͑̅͠-̐̓̅-̓̾̅̕-̽̅͘-͑͊̓̅-̈́̀̅-͆̒̔̅-̾̾̒̅-͒͌̈́̅-̓͆̈́̅-̿͒̅-̾́̅͠-͊̒̅͘-̈́͆̈́̅
*/
#include <bits/stdc++.h>
using namespace std;

int bfs(int** edges , queue<pair<int, int >> q){
    int timeframe=0;
     int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

    while(!q.empty()){
        if(q.front().first==INT_MAX){
            timeframe++;
            q.pop();
            continue;
        }
       

       //Yet to doo aaaaaaaaaaaaaaaaaaaaa
    
    }
}

int main(){
    
    int m,n;
    cin>>m>>n;
    int** edges = new int*[m];
    queue<pair<int,int>> q;
    for(int i=0;i<m;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
          cin>>edges[i][j];
          if(edges[i][j]==2){
              q.push({i,j});
          }
        }
    }
    q.push({INT_MAX,INT_MAX});
   int ans =  bfs(edges,q);
   cout<<ans<<endl;

 
    
}