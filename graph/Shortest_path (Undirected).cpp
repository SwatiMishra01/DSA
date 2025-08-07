#include<unordered_map>
#include<list>
#include<queue>
#include<vector>   --------------------------------------
	              GIVEN SOURCE NODE->TERMINAL NODE
	           --------------------------------------

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	//creating adjacency list
	unordered_map<int,list<int>>adj;
	for(int i=0; i<edges.size();i++){
		int u=edges[i].first;
		int v=edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
		}

		//do bfs
		unordered_map<int,bool>visited;
		unordered_map<int,int>parent;
		queue<int>q;
		q.push(s);
		parent[s]=-1;
		visited[s]=true;





		while(!q.empty()){
			//front node nikala
			int front= q.front();
			q.pop();
             

			 //neighbour front node k visited mark kiye 
			 //parent alot kiya neighbour ko
			 // queue mein dala
			for(auto neighbour: adj[front]){
				if(!visited[neighbour]){
				visited[neighbour]=true;
				parent[neighbour]=front;
				q.push(neighbour);
				}
			}
		}



                //prepare shortest path
				vector<int>ans;
				int currNode=t;
				ans.push_back(t);

				while(currNode!=s){
					currNode=parent[currNode];
					ans.push_back(currNode);
				}
                reverse(ans.begin(), ans.end());
				return ans;


	
}
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
        ----------------------------
	SOURCE NODE TO EVERY NODE-> 
	----------------------------
	class Solution {
public:
    
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V = adj.size();  // Number of nodes
        vector<int> dist(V, -1);  // Distance from source to each node
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(src);
        visited[src] = true;
        dist[src] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    dist[neighbour] = dist[node] + 1;
                    q.push(neighbour);
                }
            }
        }

        return dist;
    }
};
