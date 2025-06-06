# https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION



For Example :

Input: N = 3 , Edges =  [[1, 2], [2, 3], [1, 3]].
Output: Yes

Explanation : There are a total of 3 vertices in the graph. There is an edge between vertex 1 and 2, vertex 2 and 3 and vertex 1 and 3. So, there exists a cycle in the graph. 
 ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                              BFS APPROACH
#include<unordered_map>
#include<queue>
#include<list>
#include<string>
#include<vector>

bool isCyclicBFS(int src ,unordered_map<int,bool>&visited,  
unordered_map<int, list<int>>&adjList){
unordered_map<int,int>parent;
parent[src]=-1;
visited[src]=1;
 queue<int>q;
 q.push(src);

 while(!q.empty()){
     int front=q.front();
     q.pop();


     for(auto neighbour: adjList[front]){
         if(visited[neighbour]==true && neighbour!=parent[front]){
             return true;
         }
         else if(!visited[neighbour]){
             q.push(neighbour);
             visited[neighbour]=1;
             parent[neighbour]=front;
         }
     }
 }
 return false;
}




string cycleDetection (vector<vector<int>>& edges, int n, int m) //main statement
{
    // create adjacency list
    unordered_map<int, list<int>>adjList;
    for(int i=0; i<m; i++){
    int u=edges[i][0];
    int v=edges[i][1];

    adjList[u].push_back(v);
    adjList[v].push_back(u);

        }
 //to handle disconnected components
 unordered_map<int,bool>visited;
 for(int i=0; i<n; i++){
     if(!visited[i]){
         bool ans= isCyclicBFS(i, visited, adjList);
         if(ans==1)
         return "Yes";
     }
 }
 return "No";
 }
------------------------------------------------------------------------------------------------------------------------------------------------------
                                                             DFS APPROACH
 #include<unordered_map>
#include<queue>
#include<list>
#include<string>
#include<vector>

bool isCyclicDFS(int Node, int parent,unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adjList
){
 visited[Node]=true;
 for(auto neighbour: adjList[Node]){
     if(!visited[neighbour]){
         bool cycleDetected= isCyclicDFS(neighbour,Node, visited, adjList);
         if(cycleDetected)
         return true;
     }
     else if (neighbour!=parent){
         //cycle present
       return true;
     }
 }
 return false;
}




string cycleDetection (vector<vector<int>>& edges, int n, int m) //main statement
{
    // create adjacency list
    unordered_map<int, list<int>>adjList;
    for(int i=0; i<m; i++){
    int u=edges[i][0];
    int v=edges[i][1];

    adjList[u].push_back(v);
    adjList[v].push_back(u);

        }
 //to handle disconnected components
 unordered_map<int,bool>visited;
 for(int i=0; i<n; i++){
     if(!visited[i]){
         bool ans= isCyclicDFS(i,-1, visited, adjList);
         if(ans==1)
         return "Yes";
     }
 }
 return "No";
 }
