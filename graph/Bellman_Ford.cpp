# https://www.naukri.com/code360/problems/bellmon-ford_2041977?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar



vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int>dist(n+1,1e9);
    dist[src]=0;

    //n-1 times formula apply
    for(int i=0; i<n-1; i++){
        //traverse on edge list
        for(int j=0; j<m; j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];


            if(dist[u]!=1e9 && ((dist[u]+wt)<dist[v])){
                dist[v]=dist[u]+wt;

            }

        }
    }


    //check for negative cycle
    bool flag=0;
     for(int j=0; j<m; j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];


            if(dist[u]!=1e9 && ((dist[u]+wt)<dist[v])){
               flag=1;

            }

        }

        if(flag==0){
            return dist;
        }
        return vector<int>{-1};
}
