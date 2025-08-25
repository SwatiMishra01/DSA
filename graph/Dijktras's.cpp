## https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION


---------------------------------
    USING PRIORITY QUEUE
---------------------------------
    class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // adjacency list
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        // { dist, node } -> priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        
        // dist vector
        vector<int> dist(n + 1, 1e9), parent(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        dist[1] = 0;
        
        pq.push({0, 1});
        while (!pq.empty())
        {
            // Topmost element of the priority queue is with minimum distance value.
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;

            // adjacent nodes of the current popped node.
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;

                // if the previously stored distance value > current computed value -> update 
                if (dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});

                    // Update the parent of the adjNode to the recent node where it came from.
                    parent[adjNode] = node;
                }
            }
        }

        // If distance to a node could not be found, return an array containing -1.
        if (dist[n] == 1e9)
            return {-1};

        // Store the final path in the ‘path’ array.
        vector<int> path;
        int node = n;

        // Iterate backwards from destination to source through the parent array.
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(node); // push the source instead of hard-coding '1'

        // Since the path stored is in a reverse order, we reverse the array
        // to get the final answer and then return the array.
        reverse(path.begin(), path.end());

        // Insert the distance at the beginning (as GfG expects)
        path.insert(path.begin(), dist[n]);

        return path;
    }
};

T.C=O(E log V)
S.C=
O(V + E) for adjacency list.
O(E) extra because of duplicates in the heap.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
    ---------------------------------
       USING SET-> BETTER OPTION
    ----------------------------------

#include<unordered_map>
#include<list>
#include<set>

#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // creating adjacency list
     unordered_map<int,list<pair<int,int>>>adj;
     for(int i=0; i<edges; i++){
        int u=vec[i][0];  //1st node
        int v=vec[i][1];  //2nd node
        int w=vec[i][2];  //weight


        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
     }


//distance vector bnao with infinite value
     vector<int>dist(vertices);
     for(int i=0; i<vertices; i++){
         dist[i]=INT_MAX;
     }

//set vector banao pair<dist,node> ka
         set<pair<int,int>>st;
         dist[source]=0;
         st.insert(make_pair(0,source));


        /////dijktra's logic//////
         while(!st.empty()){
             //fetch top node
             auto top=*(st.begin());
             int nodeDist=top.first;
             int topNode= top.second;

             //delete krdo set see us pair ko
             st.erase(st.begin());


             //traversing neighbours
             for(auto neighbour:adj[topNode]){
                 if(nodeDist + neighbour.second < dist[neighbour.first]){


                     //find ki is node se already pada hua h kya?
                     auto record= st.find(make_pair(dist[neighbour.first],neighbour.first));
                     if(record!=st.end()){
                         st.erase(record); 
                     }
                   // distance update
                   dist[neighbour.first]=nodeDist + neighbour.second;
                   //push in set
                   st.insert(make_pair(dist[neighbour.first],neighbour.first));
             }
         }

         
     }
     return dist;
}
T.C=O((V + E) log V)
s.c=
O(V + E) for adjacency list.
No extra duplicates → cleaner O(V) storage in the set.
