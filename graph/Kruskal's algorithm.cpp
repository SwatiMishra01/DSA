# https://www.naukri.com/code360/problems/minimum-spanning-tree_631769?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&count=25&search=&sort_entity=order&sort_order=ASC&attempt_status=NOT_ATTEMPTED&leftPanelTabValue=SUBMISSION

🔧 STEPS


1. Sort all edges by weight
-- Use a custom comparator cmp to sort the edges in ascending order of their weights.

2. Initialize Disjoint Set (Union-Find):
-- makeSet() initializes two arrays:
-- parent[i] = i (Each node is its own parent initially)
-- rank[i] = 0 (Used for union by rank optimization)

3. Iterate through all edges (sorted order):
-- For each edge {u, v, wt}:
     -- Find the ultimate parent of both u and v using findParent().
     -- If they belong to different sets (no cycle), include the edge in MST:
       --> Add wt to minWeight.
       --> Union their sets using unionSet() to merge the components.

4. Return the total weight:
-- Once all nodes are connected (or all edges are checked), return the accumulated minWeight.

       
-------------------------------------------------------------------------------------------------------------------------------------------------
🧠 Concepts Used:
1. Greedy Algorithm: Always pick the smallest edge. 
2. Disjoint Set Union (DSU):
  -- Path Compression in findParent() to flatten the tree.
  -- Union by Rank in unionSet() to keep trees shallow for efficiency.
-------------------------------------------------------------------------------------------------------------------------------------------------



#include <algorithm>
bool cmp(vector<int>&a, vector<int>&b){
  return a[2]<b[2];
}






void makeSet(vector<int>&parent, vector<int>&rank, int n){
  for(int i=0; i<n; i++){
    parent[i]=i;
    rank[i]=0;

  }

}


int findParent(vector<int>&parent , int node){
  if(parent[node]==node){
    return node;
  }
  return parent[node]=findParent(parent,parent[node]);
}

void unionSet(int u, int v, vector<int>&parent, vector<int>&rank){
  u= findParent(parent,u);
  v= findParent(parent,v);


  if(rank[u]<rank[v]){
    parent[u]=v;
  }
  else if(rank[v]<rank[u]){
    parent[v]=u;
  }
  else{
    parent[v]=u;
    rank[u]++;
  }
}


int minimumSpanningTree(vector<vector<int>>& edges, int n)   //main statement
{
  sort(edges.begin(), edges.end(),cmp);
  vector<int>parent(n);
  vector<int>rank(n);
  makeSet(parent,rank,n);

int minWeight=0;
  for(int i=0; i<edges.size(); i++){
    int u=findParent(parent,edges[i][0]);
    int v=findParent(parent,edges[i][1]);
    int wt=edges[i][2];

    if(u!=v){
      minWeight+=wt;
       unionSet(u,v,parent, rank);
    }
  }
   return minWeight;
}
