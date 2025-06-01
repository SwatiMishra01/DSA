## https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION




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
