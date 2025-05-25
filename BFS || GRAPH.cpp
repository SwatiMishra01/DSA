
# https://www.naukri.com/code360/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM


Problem statement
Given an adjacency list representation of a directed graph with ‘n’ vertices and ‘m’ edges. Your task is to return a list consisting of Breadth-First Traversal (BFS) starting from vertex 0.
In this traversal, one can move from vertex 'u' to vertex 'v' only if there is an edge from 'u' to 'v'. The BFS traversal should include all nodes directly or indirectly connected to vertex 0.
Note:
The traversal should proceed from left to right according to the input adjacency list.
Example:
Adjacency list: { {1,2,3},{4}, {5}, {},{},{}}

The interpretation of this adjacency list is as follows:
Vertex 0 has directed edges towards vertices 1, 2, and 3.
Vertex 1 has a directed edge towards vertex 4.
Vertex 2 has a directed edge towards vertex 5.
Vertices 3, 4, and 5 have no outgoing edges.


BFS traversal: 0 1 2 3 4 5
  -----------------------------------------------------------------------------------------------------------------------------------------------------------------
  
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> bfs;            // To store BFS order
    vector<bool> visited(n, false); // To keep track of visited nodes
    queue<int> q;

    // Start from vertex 0
    visited[0] = true;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        bfs.push_back(u);

        // Traverse all adjacent vertices of u in order
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i]; 
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return bfs;
    }
  
