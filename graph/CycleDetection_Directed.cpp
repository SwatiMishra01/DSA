# https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
Sample Input 1 :
1
5
6
1 2
4 1
2 4
3 4
5 2
1 3
Sample Output 1 :
true
Explanation For Input 1 :
The given graph contains cycle 1 -> 3 -> 4 -> 1 or the cycle 1 -> 2 -> 4 -> 1.



-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                   DFS APPROACH
  --------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include<unordered_map>
#include <vector>
#include<list>

bool checkCycle(int node,unordered_map<int,bool>&visited,  unordered_map<int,bool>&dfsVisited,
unordered_map<int,list<int>>&adj){
  visited[node]=true;
  dfsVisited[node]=true;

   //ab adjacent node pe jao
   for(auto neighbour:adj[node]){
     if(!visited[neighbour]){
       bool cycleDetected= checkCycle(neighbour, visited,dfsVisited, adj);
       if(cycleDetected)
       return true;
     }
     else if(dfsVisited[neighbour]){
       return true;
     }
   }
   //upar jaane se phle dfsvisited ko false mark kardo
   dfsVisited[node]=false;
   return false;

}





int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int,list<int>>adj;
  for (int i=0; i<edges.size(); i++){
    int u=edges[i].first;
    int v=edges[i].second;

    //quki directed graph h to 
    adj[u].push_back(v);
  }


  //call dfs for all components
  unordered_map<int,bool>visited;
  unordered_map<int,bool>dfsVisited;

  for (int i=0;i<n; i++){
    if(!visited[i]){
    bool cycleFound= checkCycle(i, visited,dfsVisited, adj);
    if(cycleFound)
    return true;
    }
  }
  return false;
}


---------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                   BFS APPROACH
  --------------------------------------------------------------------------------------------------------------------------------------------------------------
  #include <bits/stdc++.h> 
#include<unordered_map>
#include <vector>
#include<list>
#include <queue>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int,list<int>>adj;
  for (int i=0; i<edges.size(); i++){
    int u=edges[i].first-1;
    int v=edges[i].second-1;

    //quki directed graph h to 
    adj[u].push_back(v);
  }

//calculating indegrees
vector<int>indegree(n);
for(auto i:adj){
  for(auto j:i.second){
    indegree[j]++;
    }
  }


  //queue banakr 0 indegree valo ko store kardo
  queue<int>q;
  for(int i=0; i<n; i++){
  if(indegree[i]==0){
    q.push(i);
  }}

  //do BFS
  int count=0;
  while(!q.empty()){
    int front=q.front();
    q.pop();
    //increment count
    count++;


  //indegree update
  for(auto neighbour:adj[front]){
    indegree[neighbour]--;
    //jiska indegree 0 hogya use queue m daaldo
    if(indegree[neighbour]==0){
      q.push(neighbour);
    }
  }
  }
 if(count ==n){
   return false;}
   else{
     return true;
 }



}
