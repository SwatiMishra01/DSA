# https://www.naukri.com/code360/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM


🔹 Step-by-step Explanation:

1. Build Original Graph (Adjacency List)
Convert the edge list into a graph using adjacency list.

2. Topological Sort (Using DFS)
Do a DFS traversal and store the nodes in a stack after visiting all descendants.
This gives the finishing order of nodes.

3. Transpose the Graph
Reverse the direction of all edges.

4. DFS on Transposed Graph (in stack order)
- Pop each node from the stack.
- If unvisited, do a DFS in transposed graph → this gives one SCC.
- Count how many such DFS calls happen


---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include<unordered_map>
#include<list>
#include<stack>   
  
   //function for topological_sorting
   void topological_sort(int node,unordered_map<int,bool>&visited,stack<int>&s,
      unordered_map<int,list<int>>&adj ){
        visited[node]=true;
          for(auto neighbour:adj[node]){
              if(!visited[neighbour]){
                topological_sort(neighbour,visited,s,adj);
        }
    }
    //imp-topologiocal logic
    s.push(node);
}



//function to print reverse_dfs
void reverse_dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj ){
visited[node]=true;
for(auto neighbour:adj[node]){
	if(!visited[neighbour]){
		reverse_dfs(neighbour,visited,adj);
	}
}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// adjacency list
	unordered_map<int,list<int>>adj;
	for(int i=0; i<edges.size();i++){
	int u=edges[i][0];
	int v=edges[i][1];

	adj[u].push_back(v);
	}

	//topological sort
	unordered_map<int,bool>visited;
	stack<int>s;
	for(int i=0; i<v; i++){
		if(!visited[i]){
			topological_sort(i,visited,s,adj);
		}
	}



	//create a transpose graph
	unordered_map<int,list<int>>transpose;
	for(int i=0; i<v; i++){
		visited[i]=0;
		for(auto neighbour:adj[i]){
			transpose[neighbour].push_back(i);
		}
	}


	//dfs call using above ordering
	int count=0;
   while(!s.empty()){
   int top=s.top();
   s.pop();
   if(!visited[top]){
       count++;
	   reverse_dfs(top,visited,transpose);
   }
   }
    return count;

}
