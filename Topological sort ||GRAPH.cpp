# https://www.naukri.com/code360/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
----------------------------------------------------------------------------------------------------------------------------------------
  #include <bits/stdc++.h> 
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>

void topological_sort(int node,  unordered_map<int,bool>&visited, stack<int>&s,
unordered_map<int,list<int>>&adj){
    visited[node]=true;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            topological_sort(neighbour,visited,s,adj);
        }
    }
    //imp
    s.push(node);
}


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //creating adjacency list
    unordered_map<int,list<int>>adj;
    for(int i=0; i<e; i++){
    int u=edges[i][0]; //Agar edges ek vector<vector<int>> hai to edges[i][0] use hota hai, 
    int v=edges[i][1]; //aur agar vector<pair<int,int>> hai to edges[i].first use hota hai.

    //list banao
    adj[u].push_back(v); //directed h to ek hi ayega
    }

    //call dfs topological sort util function for all components
    unordered_map<int,bool>visited;
    stack<int>s;
    for ( int i=0; i<v; i++){
         if(!visited[i])
         topological_sort(i,visited,s, adj);
    }
   // stack se answer "ans" mein store krwana h
   vector<int>ans;
   while(!s.empty()){
   ans.push_back(s.top());
   s.pop();
   }
   return ans;
}
