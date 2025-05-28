# https://www.naukri.com/code360/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  
  
                                                                                               KAHNS ALGORITHM
  
  
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  
  
  
#include <bits/stdc++.h> 
#include<vector>
#include<queue>
#include<unordered_map>
#include<list>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // creating adjacency list
    unordered_map<int,list<int>>adj;
    for(int i=0; i<e; i++){
        int u=edges[i][0];
        int vtx =edges[i][1];
        adj[u].push_back(vtx);
    }

    //calculating indegrees
    vector<int>indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    } 


    //queue banakr 0 indegree valo ko oush kardo
   queue<int>q;
    for(int i=0; i<v; i++){
        if(indegree[i]==0)
        q.push(i);
    }

    //do BFS
    vector<int>ans;
    while(!q.empty()){
    int front=q.front();
    q.pop();
    ans.push_back(front);

 //neighbour indegree upadte
 for(auto neighbour:adj[front]){
     indegree[neighbour]--;
     if(indegree[neighbour]==0)
     q.push(neighbour);
 }
 }
 return ans;

}
