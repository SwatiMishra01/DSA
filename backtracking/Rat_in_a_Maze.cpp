N * N Matrix=
1-> open path
0-> close path

rat [0,0]->destination[N-1,N-1]
MOVEMENT- U,D,L,R
LEXICOGRAPHICAL ORDER- D,L,R,U


APPROACH:
Condition:
node is safe agar:
--> arr[naya x][naya y]==1
--> visited [naya x] [naya y] !=0
--> matrix ke andar ho bahar na jaaye
      * naya x >=0 and <n
      * naya y >=0 and <n

EX:   1 0 0 0
      1 1 0 0
      1 1 0 0
      0 1 1 1 

f([0,0], " ")->(D,L,R,U)    #starting adress and visited ndirection       <-------
            |                                                                     |
            |      DOWN         #visited[0,0]=1                                   |
            |                  ----------------------------------------------------
f([1,0],"D")->(D,L,R,U)        <----------------------
            |                                        |
            |     DOWN          #visited[1,0]=1      |
            |                   ----------------------
f([2,0],"DD")->(D,L,R,U)        <-----------------------
            |                                           |
            |     RIGHT          #visited[2,0]=1        |
            |                    ------------------------
f([2,1],"DDR")->(D,L,R,U)        <------------------------
            |                (L,R,U check krna baaki h)  |    BACKTRACK & v[3,1]=0
            |       DOWN        #visited[2,1]=1          |
            |                     ------------------------
f([3,1],"DDRD")->(D,L,R,U)        <------------------------ 
            |                      (U check krna baki)    |    BACKTRACK & v[3,2]=0
            |       RIGHT        #visited[3,1]=1          | 
            |                         ---------------------
f([3,2],"DDRDR")->(D,L,R,U)            <--------------------
            |                                              |
            |         RIGHT      #visited[3,2]=1           |
            |                                              |
f([3,3],"DDRDRR")->(D,L,R,U)          ----------------------



CODE:-
#include <bits/stdc++.h> 
bool isSafe( int newx, int newy, vector<vector<bool>>&vis,
            vector < vector < int >> & arr, int n){
  #the 3 conditions
    if((newx >=0 && newx <n) && (newy>=0 && newy<n) && 
        vis[newx][newy] !=1 && arr[newx][newy]==1 ){
          return true;
        }
  else
    return false;
            }


void solve(int x, int y, vector < vector < int >> & arr, int n, vector<string> &ans,
             vector<vector<bool>>&vis ,string path){
  ##base case
  if(x==n-1 && y==n-1){
    ans.push_back(path);
    return;
  }
     ## movements-D,L,R,U
      vis[x][y]=1;
     ##DOWN
     if(isSafe(x+1, y, vis, arr, n)){
       solve(x+1,y,arr,n,ans,vis,path +'D');
     }
          ##LEFT
     if(isSafe(x, y-1, vis, arr, n)){
       solve(x,y-1,arr,n,ans,vis,path +'L');
     }
          ##RIGHT
     if(isSafe(x, y+1, vis, arr, n)){
       solve(x,y+1,arr,n,ans,vis,path +'R');
     }
          ##UP
     if(isSafe(x-1, y, vis, arr, n)){
       solve(x-1,y,arr,n,ans,vis,path +'U');
     }
     vis[x][y]=0;
     
 }
  




vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string>ans;
  vector<vector<bool>> visited(n,vector<bool>(n,0));
  string path="";

  ##edge case
  if(arr[0][0]==0)
    return ans;

  solve(0,0,arr,n,ans,visited,path);
  return ans;
}


















