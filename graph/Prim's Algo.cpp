# https://www.naukri.com/code360/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION

---------------------------------
    BRUTE FORCE
-----------------------------------
#include <bits/stdc++.h> 
#include <unordered_map>
#include <list>
#include <limits.h>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // creation of adjacency list
    unordered_map<int, list<pair<int,int>>>adj;
    for(int i=0; i<g.size(); i++){
        int u=g[i].first.first;
         int v=g[i].first.second;
          int w=g[i].second;
          adj[u].push_back(make_pair(v,w));
          adj[v].push_back(make_pair(u,w));

    }

    //making 3 data structures-key,mst and parent
    vector<int>key(n+1);
    vector<bool>mst(n+1);
    vector<int>parent(n+1);


    for(int i=0 ; i<=n; i++){
        //putting key values to infinity, all parents to -1, all mst values to false
        key[i]=INT_MAX;
        parent[i]=-1;
        mst[i]=false;
    }


    //starting prim's algorithm
    key[1]=0;
    parent[1]=-1;

    for(int i=0; i<n; i++ ){
        int mini=INT_MAX;
        int u;
       //finding mini wali node
        for(int v=1; v<=n; v++){
            if(mst[v]==false && key[v]<mini){
                u=v;
                mini=key[v];

            }
        }

        //mark min node as true
        mst[u]=true;
        //check its adjacent nodes
        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            if(mst[v]==false && w<key[v]){
                parent[v]=u;
                key[v]=w;
            }
        }
    }

     vector<pair<pair<int, int>, int>> result;
     //loop 1 se nhi chla skte quki parent[1]=-1
     for(int i=2; i<=n; i++){
         result.push_back({{parent[i],i}, key[i]});

     }

   return result;
}
T.C=O(N^2)
S.C=o(n+m)

---------------------------------------------------------------------------------------------------------------------------------------------------------------------
    --------------------------
     USING PRIORITY QUEUE
    --------------------------
    #include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // creation of adjacency list
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i=0; i<m; i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    // data structures: key, parent, mst
    vector<int> key(n+1, INT_MAX);
    vector<bool> mst(n+1, false);
    vector<int> parent(n+1, -1);

    // min-heap {weight, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    // start from node 1
    key[1] = 0;
    pq.push({0,1});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if(mst[u]) continue; // if already included in MST, skip
        mst[u] = true;

        // check adjacent nodes
        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;

            if(!mst[v] && w < key[v]){
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    // store MST result
    vector<pair<pair<int, int>, int>> result;
    for(int i=2; i<=n; i++){
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}
T.C=O((n + m) log n)
S.C=O(N+M)
