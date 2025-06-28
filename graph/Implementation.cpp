# https://www.naukri.com/code360/problems/create-a-graph-and-print-it_1214551?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
For Example:
If 'N' = 3 and edges = {{2,1}, {2,0}}.
 So, the adjacency list of the graph is stated below.
0 → 2
1 → 2
2 → 0 → 1
  -----------------------------------------------------------------------------------------------------------------------
  vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<int>ans[n];
    //ans array will store all the adjacent nodes corresponding on indexes
    for(int i=0; i<m; i++){
        int u= edges[i][0];
        int v= edges[i][1]; 
        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    vector<vector<int>>adj(n);
    for(int i=0; i<n; i++){
        //phle vhi node dala
        adj[i].push_back(i);
        for(int j=0; j<ans[i].size(); j++){
            //baaki neighbourse daldiye
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
};
