https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int>ans;
        if(root==NULL) return ans;
        
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        
        
        q.push({root,0});
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node*node=it.first;
            int line=it.second;
            
            if(mp.find(line)==mp.end() ) mp[line]=(node->data);
            
            if(node->left) q.push({node->left,line-1});
            if(node->right) q.push({node->right,line+1});
        }
        
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
T.C=O(N)
S.C= O(N/2 + N/2)
->N/2 nodes which is the maximum width.
-> map have N/2 entries as well.
