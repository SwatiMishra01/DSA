# https://www.naukri.com/code360/problems/bridges-in-graph_893026?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  🔍 Approach to Find Bridges (Tarjan’s Algorithm)


  
1. Build Adjacency List from the given edge list.
2. Initialize:
     - disc[] → Discovery time of each node (when it was first visited).
     - low[] → Lowest discovery time reachable from the node (via DFS tree or back edge).
     - visited[] → To track visited nodes.
     - timer = 0 → Global timer for discovery times.

3. Run DFS on all unvisited nodes:
    - Set disc[node] = low[node] = timer++.
    - For each neighbour:
         * Skip if it's the parent node.
         * If unvisited → Recurse DFS, update low[node] = min(low[node], low[neighbour]).
         * If visited → It's a back edge → update low[node] = min(low[node], disc[neighbour]).
    - After visiting all neighbours:
         * If low[neighbour] > disc[node] → it's a bridge.






💡 Bridge Condition:
low[neighbour] > disc[node]
Means there’s no other way to reach node or ancestors of node from neighbour.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



#include<unordered_map>
#include<list>



void dfs(int node, int parent, int & timer,vector<int>&disc, vector<int>& low,
vector<vector<int>>& result, unordered_map<int, list<int>>& adj , 
unordered_map<int,bool>&visited ){
visited[node]=true;
disc[node]=low[node]=timer++;


for(auto neighbour:adj[node]){
    if(neighbour==parent)
        continue;
        if(!visited[neighbour]){
         dfs(neighbour,node,timer,disc , low, result, adj, visited);
         //update low[node]
         low[node]=min(low[node],low[neighbour]);


         //check if there is bridge
         if(low[neighbour]>disc[node]){
              result.push_back({node, neighbour});
        }
        }
        else{
          //back edge
          low[node]=min(low[node], disc[neighbour]);
        }

}

}



vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // adj list
     unordered_map<int, list<int>>adj;
     for(int i=0; i<edges.size(); i++){
     int u=edges[i][0];
     int v=edges[i][1];

     adj[u].push_back(v);
     adj[v].push_back(u);
     }

     int timer=0;
     vector<int>disc(v);
     vector<int>low(v);
     int parent=-1;
     unordered_map<int,bool>visited;


     for(int i=0; i<v; i++){
         disc[i]=-1;
         low[i]=-1;
         visited[i]=false;
     }
      vector<vector<int>>result;
     //dfs
     for(int i=0; i<v; i++){
         if(!visited[i]){
             dfs(i,parent,timer,disc,low,result,adj, visited);
         }
     }
     return result;


}
